/*
===========================================================================

Doom 3 GPL Source Code
Copyright (C) 1999-2011 id Software LLC, a ZeniMax Media company.

This file is part of the Doom 3 GPL Source Code ("Doom 3 Source Code").

Doom 3 Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Doom 3 Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Doom 3 Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, the Doom 3 Source Code is also subject to certain additional terms. You should have received a copy of these additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Doom 3 Source Code.  If not, please request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.

===========================================================================
*/

#include "precompiled.h"
#pragma hdrstop

#include "D3Base_local.h"

/*
===========
idGame::CreateInstance
============
*/
idGame * CreateInstance( void ) {
	gameLocal = new idD3BaseLocal();
	return gameLocal;
}

/*
===========
idD3BaseLocal::idD3BaseLocal
============
*/
idD3BaseLocal::idD3BaseLocal() {
	Clear();
}

/*
===========
idD3BaseLocal::Clear
============
*/
void idD3BaseLocal::Clear( void ) {
	locationEntities = NULL;
}

/*
===========
idD3BaseLocal::Init

  initialize the game object, only happens once at startup, not each level load
============
*/
void idD3BaseLocal::Init( void ) {
	idGameLocal::Init();

	Printf( "--------- Initializing Doom 3 ----------\n" );
	Printf( "Name: %s\n", GAME_VERSION );
	Printf( "Date: %s\n", __DATE__ );

	// register game specific decl folders
	declManager->RegisterDeclFolder( "newpdas",			".pda",				DECL_PDA );

	Printf( "Doom 3 Game initialized.\n" );
	Printf( "--------------------------------------\n" );
}

/*
===================
idD3BaseLocal::MapPopulate
===================
*/
void idD3BaseLocal::MapPopulate( void ) {
	idGameLocal::MapPopulate();

	// mark location entities in all connected areas
	SpreadLocations();
}

/*
===========
idD3BaseLocal::MapClear
===========
*/
void idD3BaseLocal::MapClear( bool clearClients ) {
	idGameLocal::MapClear( clearClients );

	delete[] locationEntities;
	locationEntities = NULL;
}

/*
===========
idD3BaseLocal::Shutdown

  shut down the entire game
============
*/
void idD3BaseLocal::Shutdown( void ) {

	idGameLocal::Shutdown();

	Printf( "------------ Doom 3 Shutdown -----------\n" );

	delete[] locationEntities;
	locationEntities = NULL;

	Printf( "--------------------------------------\n" );
}

/*
======================
idD3BaseLocal::ModSave
======================
*/
void idD3BaseLocal::ModSave( idSaveGame *saveGame ) {
	if ( !locationEntities ) {
		saveGame->WriteInt( 0 );
	} else {
		saveGame->WriteInt( gameRenderWorld->NumAreas() );
		for( int i = 0; i < gameRenderWorld->NumAreas(); i++ ) {
			saveGame->WriteObject( locationEntities[ i ] );
		}
	}
}

/*
======================
idD3BaseLocal::ModRestore
======================
*/
void idD3BaseLocal::ModRestore( idRestoreGame *restoreGame ) {
	int num;

	restoreGame->ReadInt( num );
	if ( num ) {
		if ( num != gameRenderWorld->NumAreas() ) {
			restoreGame->Error( "idD3BaseLocal::ModRestore: number of areas in map differs from save game." );
		}

		locationEntities = new idLocationEntity *[ num ];
		for( int i = 0; i < num; i++ ) {
			restoreGame->ReadObject( reinterpret_cast<idClass *&>( locationEntities[ i ] ) );
		}
	}
}

/*
======================
idD3BaseLocal::SpreadLocations

Now that everything has been spawned, associate areas with location entities
======================
*/
void idD3BaseLocal::SpreadLocations() {
	idEntity *ent;

	// allocate the area table
	int	numAreas = gameRenderWorld->NumAreas();
	locationEntities = new idLocationEntity *[ numAreas ];
	memset( locationEntities, 0, numAreas * sizeof( *locationEntities ) );

	// for each location entity, make pointers from every area it touches
	for( ent = spawnedEntities.Next(); ent != NULL; ent = ent->spawnNode.Next() ) {
		if ( !ent->IsType( idLocationEntity::Type ) ) {
			continue;
		}
		idVec3	point = ent->spawnArgs.GetVector( "origin" );
		int areaNum = gameRenderWorld->PointInArea( point );
		if ( areaNum < 0 ) {
			Printf( "SpreadLocations: location '%s' is not in a valid area\n", ent->spawnArgs.GetString( "name" ) );
			continue;
		}
		if ( areaNum >= numAreas ) {
			Error( "idD3BaseLocal::SpreadLocations: areaNum >= gameRenderWorld->NumAreas()" );
		}
		if ( locationEntities[areaNum] ) {
			Warning( "location entity '%s' overlaps '%s'", ent->spawnArgs.GetString( "name" ),
				locationEntities[areaNum]->spawnArgs.GetString( "name" ) );
			continue;
		}
		locationEntities[areaNum] = static_cast<idLocationEntity *>(ent);

		// spread to all other connected areas
		for ( int i = 0 ; i < numAreas ; i++ ) {
			if ( i == areaNum ) {
				continue;
			}
			if ( gameRenderWorld->AreasAreConnected( areaNum, i, PS_BLOCK_LOCATION ) ) {
				locationEntities[i] = static_cast<idLocationEntity *>(ent);
			}
		}
	}
}

/*
===================
idD3BaseLocal::LocationForPoint

The player checks the location each frame to update the HUD text display
May return NULL
===================
*/
idLocationEntity *idD3BaseLocal::LocationForPoint( const idVec3 &point ) {
	if ( !locationEntities ) {
		// before SpreadLocations() has been called
		return NULL;
	}

	int areaNum = gameRenderWorld->PointInArea( point );
	if ( areaNum < 0 ) {
		return NULL;
	}
	if ( areaNum >= gameRenderWorld->NumAreas() ) {
		Error( "idD3BaseLocal::LocationForPoint: areaNum >= gameRenderWorld->NumAreas()" );
	}

	return locationEntities[ areaNum ];
}
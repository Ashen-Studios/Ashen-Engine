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

#ifndef __GAME_DEFINES_H__
#define __GAME_DEFINES_H__

/*
===============================================================================

	Defines use by the game module.

===============================================================================
*/

// default scripts
#define SCRIPT_DEFAULTDEFS		"script/doom_defs.script"
#define SCRIPT_DEFAULT			"script/doom_main.script"
#define SCRIPT_DEFAULTFUNC		"doom_main"

#define LAGO_IMG_WIDTH			64
#define LAGO_IMG_HEIGHT			64
#define LAGO_WIDTH				64
#define LAGO_HEIGHT				44
#define LAGO_MATERIAL			"textures/sfx/lagometer"
#define LAGO_IMAGE				"textures/sfx/lagometer.tga"

#define TIME_GROUP1				0
#define TIME_GROUP2				1

// if set to 1 the server sends the client PVS with snapshots and the client compares against what it sees
#ifndef ASYNC_WRITE_PVS
	#define ASYNC_WRITE_PVS		0
#endif

// the "gameversion" client command will print this plus compile date
#define	GAME_VERSION			"baseDOOM-1"

#define	MAX_CLIENTS				32
#define	GENTITYNUM_BITS			12
#define	MAX_GENTITIES			(1<<GENTITYNUM_BITS)
#define	ENTITYNUM_NONE			(MAX_GENTITIES-1)
#define	ENTITYNUM_WORLD			(MAX_GENTITIES-2)
#define	ENTITYNUM_MAX_NORMAL	(MAX_GENTITIES-2)

#define	MAX_GAME_MESSAGE_SIZE	8192
#define	MAX_ENTITY_STATE_SIZE	512
#define	ENTITY_PVS_SIZE			((MAX_GENTITIES + 31) >> 5)
#define	NUM_RENDER_PORTAL_BITS	idMath::BitsForInteger(PS_BLOCK_ALL)

#define	MAX_EVENT_PARAM_SIZE	128

enum {
	GAME_RELIABLE_MESSAGE_INIT_DECL_REMAP,
	GAME_RELIABLE_MESSAGE_REMAP_DECL,
	GAME_RELIABLE_MESSAGE_SPAWN_PLAYER,
	GAME_RELIABLE_MESSAGE_DELETE_ENT,
	GAME_RELIABLE_MESSAGE_CHAT,
	GAME_RELIABLE_MESSAGE_TCHAT,
	GAME_RELIABLE_MESSAGE_SOUND_EVENT,
	GAME_RELIABLE_MESSAGE_SOUND_INDEX,
	GAME_RELIABLE_MESSAGE_DB,
	GAME_RELIABLE_MESSAGE_KILL,
	GAME_RELIABLE_MESSAGE_DROPWEAPON,
	GAME_RELIABLE_MESSAGE_RESTART,
	GAME_RELIABLE_MESSAGE_SERVERINFO,
	GAME_RELIABLE_MESSAGE_TOURNEYLINE,
	GAME_RELIABLE_MESSAGE_CALLVOTE,
	GAME_RELIABLE_MESSAGE_CASTVOTE,
	GAME_RELIABLE_MESSAGE_STARTVOTE,
	GAME_RELIABLE_MESSAGE_UPDATEVOTE,
	GAME_RELIABLE_MESSAGE_PORTALSTATES,
	GAME_RELIABLE_MESSAGE_PORTAL,
	GAME_RELIABLE_MESSAGE_VCHAT,
	GAME_RELIABLE_MESSAGE_STARTSTATE,
	GAME_RELIABLE_MESSAGE_MENU,
	GAME_RELIABLE_MESSAGE_WARMUPTIME,
	GAME_RELIABLE_MESSAGE_EVENT
};

typedef enum {
	GAMESTATE_UNINITIALIZED,		// prior to Init being called
	GAMESTATE_NOMAP,				// no map loaded
	GAMESTATE_STARTUP,				// inside InitFromNewMap().  spawning map entities.
	GAMESTATE_ACTIVE,				// normal gameplay
	GAMESTATE_SHUTDOWN				// inside MapShutdown().  clearing memory.
} gameState_t;


//
// these defines work for all startsounds from all entity types
// make sure to change SCRIPT_DEFAULTDEFS if you add any channels, or change their order
//
typedef enum {
	SND_CHANNEL_ANY = SCHANNEL_ANY,
	SND_CHANNEL_VOICE = SCHANNEL_ONE,
	SND_CHANNEL_VOICE2,
	SND_CHANNEL_BODY,
	SND_CHANNEL_BODY2,
	SND_CHANNEL_BODY3,
	SND_CHANNEL_WEAPON,
	SND_CHANNEL_ITEM,
	SND_CHANNEL_HEART,
	SND_CHANNEL_PDA,
	SND_CHANNEL_DEMONIC,
	SND_CHANNEL_RADIO,

	// internal use only.  not exposed to script or framecommands.
	SND_CHANNEL_AMBIENT,
	SND_CHANNEL_DAMAGE
} gameSoundChannel_t;

// content masks
#define	MASK_ALL					(-1)
#define	MASK_SOLID					(CONTENTS_SOLID)
#define	MASK_MONSTERSOLID			(CONTENTS_SOLID|CONTENTS_MONSTERCLIP|CONTENTS_BODY)
#define	MASK_PLAYERSOLID			(CONTENTS_SOLID|CONTENTS_PLAYERCLIP|CONTENTS_BODY)
#define	MASK_DEADSOLID				(CONTENTS_SOLID|CONTENTS_PLAYERCLIP)
#define	MASK_WATER					(CONTENTS_WATER)
#define	MASK_OPAQUE					(CONTENTS_OPAQUE)
#define	MASK_SHOT_RENDERMODEL		(CONTENTS_SOLID|CONTENTS_RENDERMODEL)
#define	MASK_SHOT_BOUNDINGBOX		(CONTENTS_SOLID|CONTENTS_BODY)

#define DEFAULT_GRAVITY				1066.0f
#define DEFAULT_GRAVITY_STRING		"1066"
#define DEFAULT_GRAVITY_VEC3		idVec3( 0, 0, -DEFAULT_GRAVITY )

#define CINEMATIC_SKIP_DELAY		SEC2MS( 2.0f )

#endif /* !__GAME_DEFINES_H__ */

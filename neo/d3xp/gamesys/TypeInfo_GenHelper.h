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

#ifndef _TYPEINFO_GENHELPER_H
#define _TYPEINFO_GENHELPER_H


// Make sure all game class definitions are available here for two reasons:
//  1. TypeInfo utility would parse this cpp file and it must include everything
//  2. If memory debugging is enabled, the classes are referenced in GameTypeInfo.h

#include "../d3xp/Moveable.h"
#include "../d3xp/Mover.h"
#include "../d3xp/MultiplayerGame.h"
#include "../d3xp/physics/Clip.h"
#include "../d3xp/physics/Force.h"
#include "../d3xp/physics/Force_Constant.h"
#include "../d3xp/physics/Force_Drag.h"
#include "../d3xp/physics/Force_Field.h"
#include "../d3xp/physics/Force_Grab.h"
#include "../d3xp/physics/Force_Spring.h"
#include "../d3xp/physics/Physics.h"
#include "../d3xp/physics/Physics_Actor.h"
#include "../d3xp/physics/Physics_AF.h"
#include "../d3xp/physics/Physics_Base.h"
#include "../d3xp/physics/Physics_Monster.h"
#include "../d3xp/physics/Physics_Parametric.h"
#include "../d3xp/physics/Physics_Player.h"
#include "../d3xp/physics/Physics_RigidBody.h"
#include "../d3xp/physics/Physics_Static.h"
#include "../d3xp/physics/Physics_StaticMulti.h"
#include "../d3xp/physics/Push.h"
#include "../d3xp/Player.h"
#include "../d3xp/PlayerIcon.h"
#include "../d3xp/PlayerView.h"
#include "../d3xp/Projectile.h"
#include "../d3xp/Pvs.h"
#include "../d3xp/script/Script_Compiler.h"
#include "../d3xp/script/Script_Interpreter.h"
#include "../d3xp/script/Script_Program.h"
#include "../d3xp/script/Script_Thread.h"
#include "../d3xp/SecurityCamera.h"
#include "../d3xp/Sound.h"
#include "../d3xp/Target.h"
#include "../d3xp/Trigger.h"
#include "../d3xp/Weapon.h"
#include "../d3xp/WorldSpawn.h"
#include "../d3xp/Actor.h"
#include "../d3xp/AF.h"
#include "../d3xp/AFEntity.h"
#include "../d3xp/ai/AAS.h"
#include "../d3xp/ai/AAS_local.h"
#include "../d3xp/ai/AI.h"
#include "../d3xp/anim/Anim.h"
#include "../d3xp/anim/Anim_Testmodel.h"
#include "../d3xp/BrittleFracture.h"
#include "../d3xp/Camera.h"
#include "../d3xp/Entity.h"
#include "../d3xp/FX.h"
#include "../d3xp/Game.h"
#include "../d3xp/Grabber.h"
#include "../d3xp/GameEdit.h"
#include "../d3xp/gamesys/Class.h"
#include "../d3xp/gamesys/DebugGraph.h"
#include "../d3xp/gamesys/Event.h"
#include "../d3xp/gamesys/SaveGame.h"
#include "../d3xp/gamesys/SysCmds.h"
#include "../d3xp/gamesys/SysCvar.h"
#include "../d3xp/gamesys/TypeInfo.h"
#include "../d3xp/Game_local.h"
#include "../d3xp/IK.h"
#include "../d3xp/Item.h"
#include "../d3xp/Light.h"
#include "../d3xp/Misc.h"

#endif

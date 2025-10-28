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

#include "../game/Moveable.h"
#include "../game/Mover.h"
#include "../game/MultiplayerGame.h"
#include "../game/physics/Clip.h"
#include "../game/physics/Force.h"
#include "../game/physics/Force_Constant.h"
#include "../game/physics/Force_Drag.h"
#include "../game/physics/Force_Field.h"
#include "../game/physics/Force_Spring.h"
#include "../game/physics/Physics.h"
#include "../game/physics/Physics_Actor.h"
#include "../game/physics/Physics_AF.h"
#include "../game/physics/Physics_Base.h"
#include "../game/physics/Physics_Monster.h"
#include "../game/physics/Physics_Parametric.h"
#include "../game/physics/Physics_Player.h"
#include "../game/physics/Physics_RigidBody.h"
#include "../game/physics/Physics_Static.h"
#include "../game/physics/Physics_StaticMulti.h"
#include "../game/physics/Push.h"
#include "../game/Player.h"
#include "../game/PlayerIcon.h"
#include "../game/PlayerView.h"
#include "../game/Projectile.h"
#include "../game/Pvs.h"
#include "../game/script/Script_Compiler.h"
#include "../game/script/Script_Interpreter.h"
#include "../game/script/Script_Program.h"
#include "../game/script/Script_Thread.h"
#include "../game/SecurityCamera.h"
#include "../game/Sound.h"
#include "../game/Target.h"
#include "../game/Trigger.h"
#include "../game/Weapon.h"
#include "../game/WorldSpawn.h"
#include "../game/Actor.h"
#include "../game/AF.h"
#include "../game/AFEntity.h"
#include "../game/ai/AAS.h"
#include "../game/ai/AAS_local.h"
#include "../game/ai/AI.h"
#include "../game/anim/Anim.h"
#include "../game/anim/Anim_Testmodel.h"
#include "../game/BrittleFracture.h"
#include "../game/Camera.h"
#include "../game/Entity.h"
#include "../game/FX.h"
#include "../d3base/D3Base_Defines.h"
#include "../d3base/D3Base_Edit.h"
#include "../game/gamesys/Class.h"
#include "../game/gamesys/DebugGraph.h"
#include "../game/gamesys/Event.h"
#include "../game/gamesys/SaveGame.h"
#include "../game/gamesys/SysCmds.h"
#include "../game/gamesys/SysCvar.h"
#include "../game/gamesys/TypeInfo.h"
#include "../game/Game_Local.h"
#include "../game/IK.h"
#include "../game/Item.h"
#include "../game/Light.h"
#include "../game/Misc.h"

#endif

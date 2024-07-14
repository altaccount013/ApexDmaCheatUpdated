#pragma once

constexpr uint64_t OFF_LEVEL = 0x17e8d34;                         //[Miscellaneous].LevelName
constexpr uint64_t OFF_LOCAL_PLAYER = 0x22b0328;                  //[Miscellaneous].LocalPlayer
constexpr uint64_t OFF_ENTITY_LIST = 0x01ef7b90 + 0xA8;           //[ConVars].gamepad_aim_assist_melee # [Miscellaneous].cl_entitylist

constexpr uint64_t OFF_NAME_LIST = 0xd2e2260;                    //[Miscellaneous].NameList
constexpr uint64_t OFF_NAME_INDEX = 0x38;                         //[RecvTable.DT_BaseEntity].??

constexpr uint64_t OFF_VIEWRENDER = 0x7542c00;                    //[Miscellaneous].ViewRender
constexpr uint64_t OFF_VIEWMATRIX = 0x11a350;                     //[Miscellaneous].ViewMatrix

constexpr uint64_t OFF_HEALTH = 0x0328;                           //[RecvTable.DT_Player].m_iHealth
constexpr uint64_t OFF_MAXHEALTH = 0x0470;                        //[RecvTable.DT_Player].m_iMaxHealth
constexpr uint64_t OFF_SHIELD = 0x01a0;                           //[RecvTable.DT_BaseEntity].m_shieldHealth
constexpr uint64_t OFF_MAXSHIELD = 0x01a4;                        //[RecvTable.DT_BaseEntity].m_shieldHealthMax
constexpr uint64_t OFF_PLATFORM_UID = 0x2558;					  //[RecvTable.DT_Player].m_platformUserId

constexpr uint64_t OFF_INATTACK = 0x07542d28;                     //[Buttons].in_attack
constexpr uint64_t OFF_IN_ZOOM = 0x07542ea0;					  //[Buttons].in_zoom
constexpr uint64_t OFF_IN_TOGGLE_DUCK = 0x07542d48;				  //[Buttons].in_toggle_duck
constexpr uint64_t OFF_IN_FORWARD = 0x07542c58;					  //[Buttons].in_forward
constexpr uint64_t OFF_IN_JUMP = 0x07542e28;					  //[Buttons].in_jump 
constexpr uint64_t OFF_IN_DUCK = 0x07542f18;					  //[Buttons].in_duck 
constexpr uint64_t OFF_IN_BACKWARD = 0x07542c80;				  //[Buttons].in_backward
constexpr uint64_t OFF_IN_USE = 0x07542e90;					      //[Buttons].in_use

constexpr uint64_t OFF_IN_DUCKSTATE = 0x2a70;				      //[DataMap.C_Player].m_duckState 
constexpr uint64_t OFF_WALLRUNSTART = 0x3624;					  //[DataMap.C_Player].m_wallRunStartTime
constexpr uint64_t OFF_WALLRUNCLEAR = 0x3628;					  //[DataMap.C_Player].m_wallRunClearTime float
constexpr uint64_t OFF_FLAGS = 0x00c8;							  //[DataMap.C_Player].m_fFlags
constexpr uint64_t OFF_SKYDRIVESTATE = 0x4734;					  //[RecvTable.DT_Player].m_skydiveState

constexpr uint64_t OFF_CAMERAORIGIN = 0x1ee0;                     //[Miscellaneous].CPlayer!camera_origin
constexpr uint64_t OFF_STUDIOHDR = 0x1000;                         //[Miscellaneous].CBaseAnimating!m_pStudioHdr
constexpr uint64_t OFF_BONES = 0x0db0 + 0x48;                     //[RecvTable.DT_BaseAnimating].m_nForceBone + 0x48

constexpr uint64_t OFF_LOCAL_ORIGIN = 0x017c;                     //[DataMap.C_BaseEntity].m_vecAbsOrigin
constexpr uint64_t OFF_ABSVELOCITY = 0x0170;                      //[DataMap.C_BaseEntity].m_vecAbsVelocity
constexpr uint64_t OFF_VIEW_OFFSET = 0x00e8;					  //[DataMap.C_BaseEntity].m_currentFrame.viewOffset

constexpr uint64_t OFF_ZOOMING = 0x1be1;                          //[RecvTable.DT_Player].m_bZooming
constexpr uint64_t OFF_TEAM_NUMBER = 0x0338;                      //[RecvTable.DT_BaseEntity].m_iTeamNum
constexpr uint64_t OFF_NAME = 0x0481;                             //[RecvTable.DT_BaseEntity].m_iName
constexpr uint64_t OFF_LIFE_STATE = 0x0690;                       //[RecvTable.DT_Player].m_lifeState
constexpr uint64_t OFF_BLEEDOUT_STATE = 0x2770;                   //[RecvTable.DT_Player].m_bleedoutState
constexpr uint64_t OFF_LAST_VISIBLE_TIME = 0x19a0;                //[Miscellaneous].CPlayer!lastVisibleTime
constexpr uint64_t OFF_LAST_AIMEDAT_TIME = 0x19a8;				  //[Miscellaneous].CWeaponX!lastCrosshairTargetTime
constexpr uint64_t OFF_VIEW_ANGLES = 0x2544 - 0x14;               //[RecvTable.DT_Player].m_ammoPoolCapacity - 0x14
constexpr uint64_t OFF_PUNCH_ANGLES = 0x2448;                     //[DataMap.C_Player].m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle
constexpr uint64_t OFF_YAW = 0x224c - 0x8;                        //[DataMap.C_Player].m_currentFramePlayer.m_ammoPoolCount - 0x8

constexpr uint64_t OFF_WEAPON_HANDLE = 0x1944;                    //[RecvTable.DT_BaseCombatCharacter].m_latestPrimaryWeapons
constexpr uint64_t OFF_WEAPON_INDEX = 0x1788;                     //[RecvTable.DT_WeaponX].m_weaponNameIndex
constexpr uint64_t OFF_PROJECTILESCALE = 0x19c0 + 0x04ec;         //[WeaponSettingsMeta].base + [WeaponSettings].projectile_gravity_scale
constexpr uint64_t OFF_PROJECTILESPEED = 0x19c0 + 0x04e4;         //[WeaponSettingsMeta].base + [WeaponSettings].projectile_launch_speed
constexpr uint64_t OFF_OFFHAND_WEAPON = 0x1954;                   //[DataMap.C_BaseCombatCharacter].m_latestNonOffhandWeapons
constexpr uint64_t OFF_CURRENTZOOMFOV = 0x15e0 + 0x00b8;          //[RecvTable.DT_WeaponX].m_playerData + m_curZoomFOV
constexpr uint64_t OFF_TARGETZOOMFOV = 0x15e0 + 0x00bc;           //[RecvTable.DT_WeaponX].m_playerData + [RecvTable.DT_WeaponPlayerData].m_targetZoomFOV
constexpr uint64_t OFF_WEAPON_AMMO = 0x1590;                      //[RecvTable.DT_WeaponX_LocalWeaponData].m_ammoInClip
constexpr uint64_t OFF_RELOADING = 0x15aa;						  //[RecvTable.DT_WeaponX_LocalWeaponData].m_bInReload

constexpr uint64_t OFF_GLOW_HIGHLIGHTS = 0xb0d8ff0;               //HighlightSettings
constexpr uint64_t OFF_ITEM_ID = 0x1568;						  //[RecvTable.DT_PropSurvival].m_customScriptInt
constexpr uint64_t OFF_GLOW_ENABLE = 0x26c;                       //updated OFFSET_GLOW_CONTEXT_ID 7 = enabled, 2 = disabled
constexpr uint64_t OFF_GLOW_THROUGH_WALL = 0x26c;                 //Script_Highlight_SetVisibilityType updated 2 = enabled, 5 = disabled
constexpr uint64_t OFF_GLOW_FIX = 0x278;						  //
constexpr uint64_t OFF_GLOW_HIGHLIGHT_ID = 0x029d;                //[RecvTable.DT_HighlightSettings].m_highlightGenericContexts [DT_HighlightSettings].m_highlightServerActiveStates    
constexpr uint64_t OFF_GLOW_HIGHLIGHT_TYPE_SIZE = 0x34;			  //

constexpr long OFF_TIME_BASE = 0x2098;							  //[DataMap.C_Player].m_currentFramePlayer.timeBase
constexpr long OFFSET_TRAVERSAL_START_TIME = 0x2b80;			  //[DataMap.C_Player].m_traversalStartTime
constexpr long OFFSET_TRAVERSAL_PROGRESS = 0x2b7c;                //[DataMap.C_Player].m_traversalProgress

constexpr long OFF_GRAPPLE_ACTIVE = 0x2d60;						  //[RecvTable.DT_Player].m_grappleActive
constexpr long OFF_GRAPPLE = 0x2cd0;							  //[RecvTable.DT_Player].m_grapple
constexpr long OFF_GRAPPLE_ATTACHED = 0x0048;					  //[RecvTable.DT_GrappleData].m_grappleAttached

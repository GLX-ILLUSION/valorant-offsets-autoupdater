#pragma once

#include <Windows.h>


namespace offsets
{
	

	    inline DWORD
		uworld_state,                    // @image_base 
		uworld_key,          // @image_base + (uworld_state + 0x38)
		gobj_state,                    // @image_base
		gobj_key,            // @image_base + (gobj_state + 0x38)

		fname_pool,                    // @image_base
		fname_pool_state,                    // @image_base
		fname_pool_key,      // @image_base
		fname_pool_decrypt_w,                    // @image_base
		fname_pool_decrypt_nw,                    // @image_base

		find_object,                    // @image_base
		process_event,                    // @image_base

		bone_matrix,                    // @image_base

		line_of_sight ,                    // @image_base
		skin_changer_decrypt ,                    // @image_base
		veh_deref,                    // deref_pointer_in_game_space_fn 

			enemy_outline_color,                    // @image_base (FLinearColor) 
			ally_outline_color,                    // @image_base (FLinearColor) 
			ares_outline_mode,                    // @image_base

			proj_world_to_screen,                    // @image_base (ProjectWorldToScreen)
			get_actor_bounds,                    // @image_base

			// VTables

			// World
			persistent_level,                  // @uworld (ULevel)
			owning_game_instance,                 // @uworld (UGameInstance)    
			game_state,                 // @uworld (AGameStateBase)
			levels,                 // @uworld (TArray<struct ULevel*>)

			// Game Instance
			local_players,                  // @game_instance (TArray<struct ULocalPlayer*>)

			// Level
			actor_array,                  // @level
			actor_count,    // @level + (actor_array + 0x18)

			// Local Player
			viewport_client,                  // @local_player (UGameViewportClient)
			player_controller,                  // @local_player (APlayerController)

			// Player Controller
			acknowledged_pawn,                 // @player_controller (APawn)
			player_camera,                 // @player_controller (APlayerCameraManager)
			control_rotation,                 // @player_controller (FRotator)

			// Player Pawn
			root_component,                 // @player_pawn (USceneComponent)
			damage_handler,                 // @player_pawn (UDamageableComponent)
			actor_id,                  // @player_pawn (int)
			fname_id,                  // @player_pawn (int)
			dormant,                 // @player_pawn (bool)
			player_state,                 // @player_pawn (APlayerState)
			current_mesh,                 // @player_pawn (USkeletalMeshComponent)
			inventory,                 // @player_pawn (UAresInventory)
			outline_component,                // @player_pawn (UAresOutlineComponent)
			portrait_map,                // @player_pawn (UCharacterPortraitMinimapComponent_C)
			character_map,    // @player_pawn (UShooterCharacterMinimapComponent_C)

			// Inventory
			current_equippable,                 // @inventory (AAresEquippable)

			// Minimap Component
			local_observer,                 // @player_pawn (bool)
			is_visible,                 // @player_pawn (bool)

			// Mesh
			component_to_world,                 // @mesh (FTransform)
			bone_array,                 // @mesh (FBoxSphereBounds)
			bone_count,      // @mesh (int)
			last_submit_time,
			last_render_time,   // @mesh + (last_submit_time + 0x4) 
			outline_mode,                 // @mesh (int)
			attach_children,                 // @mesh (TArray<struct UMesh*>)
			attach_children_count, // @mesh (int)

			// Player State
			team_component,                 // @player_state (UBaseTeamComponent)

			// Team Component
			team_id,                  // @team_component (int)

			// Damage Handler               
			current_health,                 // @damage_handler (float)
			max_life,  // @damange_handler + (current_health + 0x4)

			// Root Component
			relative_location,                 // @root_component (FVector)
			relative_rotation,                 // @root_component (FRotator)

			// Camera Manager
			default_fov,                 // @camera (float)
			camera_cache,                 // @camera (FCameraCacheEntry)

			// FCameraCacheEntry
			pov,                  // @camera_cache (FMinimalViewInfo)

			// FMinimalViewInfo
			location,                   // @view_info + 0x0 = Location (FVector)
			rotation,                  // @view_info (FRotator)
			current_fov,                  // @view_info (float)

			// Outline Component
			enemy_outline,                 // @outline_component (int)

			//offsets da sdk
			bone_array_cache,
			current_defuse_section, //PlantedBomb_classes.h current_defuse_section
			magazine_ammo, //Gun_classes.h -> struct UAmmoComponent* magazine_ammo;
			auth_resource_amount,
			max_ammo,
			spike_timer, //PlantedBomb_classes.h DefuseProgress //TimeRemainingToExplode
			my_hud,
			HP,
			MaxHP,
			DamageType,
			DamageSections,
			CurrentEquippableVFXState, //[~] Name: CurrentEquippableVFXState - New Offset: 0xcf0 - (Before: 0xce8)

		void initialize();
	
}

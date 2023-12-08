#include <Windows.h>
#include <fstream>
#include "json.hpp"
#include "offsets.hpp"
#include <sstream>
#include <iostream>
#include "CurlSetup.hpp"
#include <sstream>

template <typename T>
void readValue(const nlohmann::json& src, T& dest)
{
	if (!src.is_null())
	{
		if (src.is_string())
		{
			std::string value_str = src.get<std::string>();
			if (value_str.substr(0, 2) == "0x") // hex prefix
			{
				dest = static_cast<T>(std::stoul(value_str.substr(2), nullptr, 16));
			}
			else
			{
				dest = static_cast<T>(std::stoul(value_str, nullptr, 10));
			}
		}
		else
		{
			dest = src.get<T>();
		}
	}
}


void offsets::initialize()
{
	//Offsets Streaming without a json file in disk
	json json = setup_curl();
	readValue(json["offsets"]["fname_pool"], offsets::fname_pool);
	readValue(json["offsets"]["persistent_level"], offsets::persistent_level);
	readValue(json["offsets"]["owning_game_instance"], offsets::owning_game_instance);
	readValue(json["offsets"]["game_state"], offsets::game_state);
	readValue(json["offsets"]["levels"], offsets::levels);
	readValue(json["offsets"]["local_players"], offsets::local_players);
	readValue(json["offsets"]["actor_array"], offsets::actor_array);
	readValue(json["offsets"]["viewport_client"], offsets::viewport_client);
	readValue(json["offsets"]["player_controller"], offsets::player_controller);
	readValue(json["offsets"]["acknowledged_pawn"], offsets::acknowledged_pawn);
	readValue(json["offsets"]["player_camera"], offsets::player_camera);
	readValue(json["offsets"]["control_rotation"], offsets::control_rotation);
	readValue(json["offsets"]["root_component"], offsets::root_component);
	readValue(json["offsets"]["damage_handler"], offsets::damage_handler);
	readValue(json["offsets"]["actor_id"], offsets::actor_id);
	readValue(json["offsets"]["fname_id"], offsets::fname_id);
	readValue(json["offsets"]["dormant"], offsets::dormant);
	readValue(json["offsets"]["player_state"], offsets::player_state);
	readValue(json["offsets"]["current_mesh"], offsets::current_mesh);
	readValue(json["offsets"]["inventory"], offsets::inventory);
	readValue(json["offsets"]["outline_component"], offsets::outline_component);
	readValue(json["offsets"]["portrait_map"], offsets::portrait_map);
	readValue(json["offsets"]["character_map"], offsets::character_map);
	readValue(json["offsets"]["current_equippable"], offsets::current_equippable);
	readValue(json["offsets"]["local_observer"], offsets::local_observer);
	readValue(json["offsets"]["is_visible"], offsets::is_visible);
	readValue(json["offsets"]["component_to_world"], offsets::component_to_world);
	readValue(json["offsets"]["bone_array"], offsets::bone_array);
	readValue(json["offsets"]["bone_count"], offsets::bone_count);
	readValue(json["offsets"]["last_submit_time"], offsets::last_submit_time);
	readValue(json["offsets"]["last_render_time"], offsets::last_render_time);
	readValue(json["offsets"]["outline_mode"], offsets::outline_mode);
	readValue(json["offsets"]["attach_children"], offsets::attach_children);
	readValue(json["offsets"]["attach_children_count"], offsets::attach_children_count);
	readValue(json["offsets"]["team_component"], offsets::team_component);
	readValue(json["offsets"]["team_id"], offsets::team_id);
	readValue(json["offsets"]["current_health"], offsets::current_health);
	readValue(json["offsets"]["max_life"], offsets::max_life);
	readValue(json["offsets"]["relative_location"], offsets::relative_location);
	readValue(json["offsets"]["relative_rotation"], offsets::relative_rotation);
	readValue(json["offsets"]["default_fov"], offsets::default_fov);
	readValue(json["offsets"]["camera_cache"], offsets::camera_cache);
	readValue(json["offsets"]["pov"], offsets::pov);
	readValue(json["offsets"]["location"], offsets::location);
	readValue(json["offsets"]["rotation"], offsets::rotation);
	readValue(json["offsets"]["current_fov"], offsets::current_fov);
	readValue(json["offsets"]["enemy_outline"], offsets::enemy_outline);
	readValue(json["offsets"]["bone_array_cache"], offsets::bone_array_cache);
	readValue(json["offsets"]["current_defuse_section"], offsets::current_defuse_section);
	readValue(json["offsets"]["magazine_ammo"], offsets::magazine_ammo);
	readValue(json["offsets"]["auth_resource_amount"], offsets::auth_resource_amount);
	readValue(json["offsets"]["max_ammo"], offsets::max_ammo);
	readValue(json["offsets"]["spike_timer"], offsets::spike_timer);
	readValue(json["offsets"]["my_hud"], offsets::my_hud);
	readValue(json["offsets"]["HP"], offsets::HP);
	readValue(json["offsets"]["MaxHP"], offsets::MaxHP);
	readValue(json["offsets"]["DamageType"], offsets::DamageType);
	readValue(json["offsets"]["DamageSections"], offsets::DamageSections);
	readValue(json["offsets"]["CurrentEquippableVFXState"], offsets::CurrentEquippableVFXState);
	readValue(json["offsets"]["fresnel_intensity"], offsets::FresnelIntensity);

	std::cout << "owning_game_instance: 0x" << offsets::owning_game_instance << std::endl;
	std::cout << "game_state: 0x" << offsets::game_state << std::endl;
	std::cout << "levels: 0x" << offsets::levels << std::endl;
	std::cout << "local_players: 0x" << offsets::local_players << std::endl;
	std::cout << "actor_array: 0x" << offsets::actor_array << std::endl;
	std::cout << "viewport_client: 0x" << offsets::viewport_client << std::endl;
	std::cout << "player_controller: 0x" << offsets::player_controller << std::endl;
	std::cout << "acknowledged_pawn: 0x" << offsets::acknowledged_pawn << std::endl;
	std::cout << "player_camera: 0x" << offsets::player_camera << std::endl;
	std::cout << "control_rotation: 0x" << offsets::control_rotation << std::endl;
	std::cout << "root_component: 0x" << offsets::root_component << std::endl;
	std::cout << "damage_handler: 0x" << offsets::damage_handler << std::endl;
	std::cout << "actor_id: 0x" << offsets::actor_id << std::endl;
	std::cout << "fname_id: 0x" << offsets::fname_id << std::endl;
	std::cout << "dormant: 0x" << offsets::dormant << std::endl;


}

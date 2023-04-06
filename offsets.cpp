#include <Windows.h>
#include <fstream>
#include "json.hpp"
#include "offsets.hpp"
#include <sstream>

template <typename T>
template <typename T>
void readValue(const nlohmann::json& src, T& dest)
{
	if (!src.is_null()) {
		if (src.is_number()) {
			dest = src.get<T>();
		}
		else if (src.is_string()) {
			std::istringstream iss{ src.get<std::string>() };
			if (!(iss >> dest)) {
				throw std::runtime_error("JSON field must be a number or a string representing a number.");
			}
		}
		else {
			throw std::runtime_error("JSON field must be a number or a string representing a number.");
		}
	}
}

void offsets::initialize()
{
	std::ifstream input_file{ "offsets.json" };
	if (!input_file.good())
		throw std::invalid_argument("Invalid offsets.json file");

	nlohmann::json json;
	input_file >> json;

	readValue(json["offsets"]["uworld_state"], offsets::uworld_state);
	readValue(json["offsets"]["uworld_key"], offsets::uworld_key);
	readValue(json["offsets"]["gobj_state"], offsets::gobj_state);
	readValue(json["offsets"]["gobj_key"], offsets::gobj_key);
	readValue(json["offsets"]["fname_pool"], offsets::fname_pool);
	readValue(json["offsets"]["fname_pool_state"], offsets::fname_pool_state);
	readValue(json["offsets"]["fname_pool_key"], offsets::fname_pool_key);
	readValue(json["offsets"]["fname_pool_decrypt_w"], offsets::fname_pool_decrypt_w);
	readValue(json["offsets"]["fname_pool_decrypt_nw"], offsets::fname_pool_decrypt_nw);
	readValue(json["offsets"]["find_object"], offsets::find_object);
	readValue(json["offsets"]["process_event"], offsets::process_event);
	readValue(json["offsets"]["bone_matrix"], offsets::bone_matrix);
	readValue(json["offsets"]["line_of_sight"], offsets::line_of_sight);
	readValue(json["offsets"]["skin_changer_decrypt"], offsets::skin_changer_decrypt);
	readValue(json["offsets"]["veh_deref"], offsets::veh_deref);
	readValue(json["offsets"]["enemy_outline_color"], offsets::enemy_outline_color);
	readValue(json["offsets"]["ally_outline_color"], offsets::ally_outline_color);
	readValue(json["offsets"]["ares_outline_mode"], offsets::ares_outline_mode);
	readValue(json["offsets"]["proj_world_to_screen"], offsets::proj_world_to_screen);
	readValue(json["offsets"]["get_actor_bounds"], offsets::get_actor_bounds);
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
}

#include "pch.h"

size_t call_back(const char* in, size_t size, size_t num, std::string* out)
{
	const size_t totalBytes(size * num);
	out->append(in, totalBytes);
	return totalBytes;
}

std::string getoffsets::fetch_data_from_url(const std::string& url, struct curl_slist* headers)
{


	CURL* curl = curl_easy_init();
	std::string response_string;

	if (!curl)
	{
		throw std::runtime_error("Failed to initialize curl.");
	}

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, call_back);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
	if (headers)
	{
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	}

	CURLcode res = curl_easy_perform(curl);
	curl_easy_cleanup(curl);

	if (res != CURLE_OK)
	{
		throw std::runtime_error("Failed to fetch data from URL.");
	}

	return response_string;
}


json getoffsets::get()
{
	struct curl_slist* headers = NULL;
	auto responseData = fetch_data_from_url("https://raw.githubusercontent.com/GLX-ILLUSION/valorant-offsets-autoupdater/main/offsets.json", headers);
	curl_slist_free_all(headers);

	return json::parse(responseData);
}

template <typename T> void getoffsets::ReadJson(const nlohmann::json& src, T& dest)
{
	if (!src.is_null())
	{
		if (src.is_string())
		{
			std::string value_str = src.get<std::string>();
			if (value_str.substr(0, 2) == "0x") 
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

void getoffsets::initialize()
{
	json json = get();
	ReadJson(json["offsets"]["fname_pool"], offsets::fname_pool);
	ReadJson(json["offsets"]["persistent_level"], offsets::persistent_level);
	ReadJson(json["offsets"]["owning_game_instance"], offsets::owning_game_instance);
	ReadJson(json["offsets"]["game_state"], offsets::game_state);
	ReadJson(json["offsets"]["levels"], offsets::levels);
	ReadJson(json["offsets"]["local_players"], offsets::local_players);
	ReadJson(json["offsets"]["actor_array"], offsets::actor_array);
	ReadJson(json["offsets"]["viewport_client"], offsets::viewport_client);
	ReadJson(json["offsets"]["player_controller"], offsets::player_controller);
	ReadJson(json["offsets"]["acknowledged_pawn"], offsets::acknowledged_pawn);
	ReadJson(json["offsets"]["player_camera"], offsets::player_camera);
	ReadJson(json["offsets"]["control_rotation"], offsets::control_rotation);
	ReadJson(json["offsets"]["root_component"], offsets::root_component);
	ReadJson(json["offsets"]["damage_handler"], offsets::damage_handler);
	ReadJson(json["offsets"]["actor_id"], offsets::actor_id);
	ReadJson(json["offsets"]["fname_id"], offsets::fname_id);
	ReadJson(json["offsets"]["dormant"], offsets::dormant);
	ReadJson(json["offsets"]["player_state"], offsets::player_state);
	ReadJson(json["offsets"]["current_mesh"], offsets::current_mesh);
	ReadJson(json["offsets"]["inventory"], offsets::inventory);
	ReadJson(json["offsets"]["outline_component"], offsets::outline_component);
	ReadJson(json["offsets"]["portrait_map"], offsets::portrait_map);
	ReadJson(json["offsets"]["character_map"], offsets::character_map);
	ReadJson(json["offsets"]["current_equippable"], offsets::current_equippable);
	ReadJson(json["offsets"]["local_observer"], offsets::local_observer);
	ReadJson(json["offsets"]["is_visible"], offsets::is_visible);
	ReadJson(json["offsets"]["component_to_world"], offsets::component_to_world);
	ReadJson(json["offsets"]["bone_array"], offsets::bone_array);
	ReadJson(json["offsets"]["bone_count"], offsets::bone_count);
	ReadJson(json["offsets"]["last_submit_time"], offsets::last_submit_time);
	ReadJson(json["offsets"]["last_render_time"], offsets::last_render_time);
	ReadJson(json["offsets"]["outline_mode"], offsets::outline_mode);
	ReadJson(json["offsets"]["attach_children"], offsets::attach_children);
	ReadJson(json["offsets"]["attach_children_count"], offsets::attach_children_count);
	ReadJson(json["offsets"]["team_component"], offsets::team_component);
	ReadJson(json["offsets"]["team_id"], offsets::team_id);
	ReadJson(json["offsets"]["current_health"], offsets::current_health);
	ReadJson(json["offsets"]["max_life"], offsets::max_life);
	ReadJson(json["offsets"]["relative_location"], offsets::relative_location);
	ReadJson(json["offsets"]["relative_rotation"], offsets::relative_rotation);
	ReadJson(json["offsets"]["default_fov"], offsets::default_fov);
	ReadJson(json["offsets"]["camera_cache"], offsets::camera_cache);
	ReadJson(json["offsets"]["pov"], offsets::pov);
	ReadJson(json["offsets"]["location"], offsets::location);
	ReadJson(json["offsets"]["rotation"], offsets::rotation);
	ReadJson(json["offsets"]["current_fov"], offsets::current_fov);
	ReadJson(json["offsets"]["enemy_outline"], offsets::enemy_outline);
	ReadJson(json["offsets"]["bone_array_cache"], offsets::bone_array_cache);
	ReadJson(json["offsets"]["current_defuse_section"], offsets::current_defuse_section);
	ReadJson(json["offsets"]["magazine_ammo"], offsets::magazine_ammo);
	ReadJson(json["offsets"]["auth_resource_amount"], offsets::auth_resource_amount);
	ReadJson(json["offsets"]["max_ammo"], offsets::max_ammo);
	ReadJson(json["offsets"]["spike_timer"], offsets::spike_timer);
	ReadJson(json["offsets"]["my_hud"], offsets::my_hud);
	ReadJson(json["offsets"]["HP"], offsets::HP);
	ReadJson(json["offsets"]["MaxHP"], offsets::MaxHP);
	ReadJson(json["offsets"]["DamageType"], offsets::DamageType);
	ReadJson(json["offsets"]["DamageSections"], offsets::DamageSections);
	ReadJson(json["offsets"]["CurrentEquippableVFXState"], offsets::CurrentEquippableVFXState);
	ReadJson(json["offsets"]["fresnel_intensity"], offsets::FresnelIntensity);

	//printing some offsets to see if everything is correct
	std::cout << "fname_pool: 0x" << offsets::fname_pool << std::endl;
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

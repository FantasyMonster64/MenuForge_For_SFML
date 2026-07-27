#pragma once
#include <string>
#include <filesystem>
#include <SFML/Graphics/Font.hpp>
#include "mcr_Types.h"

namespace mcr_Constants {
	inline constexpr uint16_t default_button_x = 650;

	inline constexpr mcr_Types::TextArr3 default_texts     { "start", "settings", "exit" };	// default buttons texts
	// default buttons positions
	inline constexpr mcr_Types::PosArr3  default_positions { 
		{ 
			{default_button_x, 120},										     
			{default_button_x, 360}, 										     
			{default_button_x, 600} 
		} 
	};	
	inline constexpr sf::Color default_color = sf::Color::Green;

	inline constexpr const char* const string_win_font = "C:\\Windows\\Fonts\\arial.ttf";
	inline const sf::Font& win_font = sf::Font{ std::filesystem::path(string_win_font) };
};
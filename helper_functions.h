#pragma once
#include "menucreator_fatal_error.h"
#include "mcr_Types.h"

namespace mcr_HelperFuncs {
	[[noreturn]] inline void fatal_error(const std::string_view& str) {
		Mcr_fatal_error err{ str };
		err.call_fatal_runtime_error();
	}
	template <typename T>
	inline void check_once(T&& func) {
		static std::once_flag flag;
		std::call_once(flag, func);
	}

	using screen_res_type = uint16_t;

	[[nodiscard]] inline const mcr_Types::ButtonSize unique_button_size(
		const screen_res_type screen_width, const screen_res_type screen_height) 
	{
		return { screen_width / 4.f, screen_height / 5.f };
	}

	[[nodiscard]] inline auto unique_button_positions (
		const sf::Vector2f& button_size,
		const screen_res_type screen_width, const screen_res_type screen_height
	)
	{
		auto button_x = screen_width / button_size.x;
		std::array<sf::Vector2f, 3> positions { {
			{ button_x, screen_height / 9.f},
			{ button_x, screen_height / 2.65f},
			{ button_x, screen_height / 1.5f }
		} };
		return positions;
	}
}

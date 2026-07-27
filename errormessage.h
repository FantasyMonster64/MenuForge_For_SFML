#pragma once

#include <string>
#include <format>

namespace mcr_ErrorMessage {
	inline constexpr std::string_view not_initialized = "Buttons weren't initialized. You have to "
		"initialize via 'init all buttons' function";
	inline std::string container_size_error(const int must_be, const int this_val) {
		return std::format (
			"the container size should be == {:d}, since there are 3 buttons, but your size == {:d}",
			must_be, this_val
		);
	}
}
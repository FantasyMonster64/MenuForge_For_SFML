#pragma once
#include "SimpleButton.h"

namespace mcr_Types {
	using ButtonsArr = std::array<std::unique_ptr<SimpleButton>, 3>;
	using Position = sf::Vector2f;
	using ButtonSize = sf::Vector2f;   //  sf::Vector2f, потому что setSize не работает с другими типами 
	using TextArr3 = std::array<std::string_view, 3>;
	using PosArr3 = std::array<mcr_Types::Position, 3>;
	using ArrIndex = uint8_t;
	using WindowSizeType = uint8_t;
	using ButtonPtr = std::unique_ptr<SimpleButton>;
	using ButtonsArrPtr = std::unique_ptr<ButtonsArr>;
}

#pragma once

#include "menucreator_fatal_error.h"
#include "menucreator_concepts.h"
#include "helper_functions.h"
#include "errormessage.h"
#include "menucreator_constants.h"

// parameters for gui game name functions
struct GuiGNParams {
    const char* game_name;
    const sf::Font& font;
    sf::Color color = sf::Color::Red;
    mcr_Types::WindowSizeType size = 50;
    sf::Vector2f pos = { 600, 50 };
};
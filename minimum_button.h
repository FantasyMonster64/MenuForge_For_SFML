#pragma once
#include <SFML/Graphics.hpp>

class Minimum_button {
public:
	Minimum_button();

    template <typename cont>
    inline void set_pos(cont&& pos) { shape.setPosition(pos); }
    template <typename cont>
    inline void set_size(cont&& size) { shape.setSize(size); }
    inline void set_color(sf::Color color) { shape.setFillColor(color); }

protected:
    sf::RectangleShape shape;
}
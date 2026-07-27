#pragma once
#include <SFML/Graphics.hpp>
#include "lib_connect.h"

class SimpleButton {
public:
    template< typename cont1, typename cont2 >
    SimpleButton(const sf::Color color, cont1&& pos, cont2&& size, const std::string_view text);
    SimpleButton();

    inline sf::RectangleShape& get_ref_shape() noexcept { return shape; }
    inline sf::RectangleShape get_shape() const noexcept { return shape; }
    
    template <typename cont>
    inline void set_pos(cont&& pos)         { shape.setPosition(pos);   }
    template <typename cont>
    inline void set_size(cont&& size)       { shape.setSize(size);       }
    inline void set_color(sf::Color color)  { shape.setFillColor(color); }

    // creating button text in the middle
    virtual void draw(sf::RenderWindow& window,
        const uint16_t text_size = 20, sf::Color text_color = sf::Color::Red);

    // Checks if the mouse cursor is over this button.
    bool contains(const sf::RenderWindow& window, const sf::Vector2i& pixel) const;

    
    bool is_clicked(sf::RenderWindow& window);

    // for functions that do NOT return a value (type void)
    template <typename T>
    void do_if_is_clicked(sf::RenderWindow& window, T&& func);

    // for functions that do return a value (WARNING: it doesn't work as expected)
    template <typename T>
    auto return_if_is_clicked(sf::RenderWindow& window, T&& func);

    std::string button_text;

protected:
    sf::RectangleShape shape;       
};


inline bool SimpleButton::contains(const sf::RenderWindow& window, const sf::Vector2i& pixel) const {
    sf::Vector2f world = window.mapPixelToCoords(pixel);
    return shape.getGlobalBounds().contains(world);
}

inline bool SimpleButton::is_clicked(sf::RenderWindow& window) {
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    return (this->contains(window, pos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));
}

template <typename T>
inline void SimpleButton::do_if_is_clicked(sf::RenderWindow& window, T&& func) {
    if (is_clicked(window)) {
        func();
    }
}

template <typename T>
inline auto SimpleButton::return_if_is_clicked(sf::RenderWindow& window, T&& func) {
    if (is_clicked(window)) {
        return func();
    }
}


template <typename cont1, typename cont2>
inline SimpleButton::SimpleButton(const sf::Color color,
    cont1&& pos, cont2&& size, const std::string_view text)
    :button_text{ text }
{
    this->shape.setFillColor(color);
    this->shape.setSize(size);
    this->shape.setPosition(pos);
}

inline SimpleButton::SimpleButton()
    :button_text{ "" }
{
    this->shape.setFillColor(sf::Color::White);
    this->shape.setSize({ 0, 0 });
    this->shape.setPosition({ 0, 0 });
}

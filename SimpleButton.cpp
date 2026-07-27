#include "SimpleButton.h"
#include "menucreator_constants.h"  

void SimpleButton::draw(sf::RenderWindow& window,
    const uint16_t text_size, sf::Color text_color)
{   
    sf::Text text{ mcr_Constants::win_font, button_text, text_size };

    // Получаем границы фигуры и текста
    auto shapeBoundsPos = shape.getGlobalBounds().position;
    auto textBoundsPos = text.getGlobalBounds().position;
    auto shapeBoundsSize = shape.getGlobalBounds().size;
    auto textBoundsSize = text.getGlobalBounds().size;

    // Вычисляем позицию для центрирования текста
    float textX = shapeBoundsPos.x + (shapeBoundsSize.x / 2.0f) -
        (textBoundsSize.x / 2.0f) - textBoundsPos.x;
    float textY = shapeBoundsPos.y + (shapeBoundsSize.y / 2.0f) -
        (textBoundsSize.y / 2.0f) - textBoundsPos.y;

    text.setPosition({ textX, textY });
    text.setFillColor(text_color);
    window.draw(get_ref_shape());
    window.draw(text);
}



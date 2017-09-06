#pragma once

#include <SFML/Graphics.hpp>

namespace Tas
{
    class InputManager
    {
    public:
        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        inline sf::Vector2i GetMousePosition(sf::RenderWindow &window){return sf::Mouse::getPosition(window);}
    };
}

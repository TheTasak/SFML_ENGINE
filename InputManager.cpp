#include "InputManager.hpp"


namespace Tas
{
    bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if(sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect spriteRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width,object.getGlobalBounds().height);
            if(spriteRect.contains(sf::Mouse::getPosition(window)))
                return true;
        }
        return false;
    }
}

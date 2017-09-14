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
    bool InputManager::isSpriteMoved(sf::Sprite &object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        sf::Vector2f lastPos = sf::Mouse.getPosition();
        while(sf::Mouse::isButtonPressed(button))
        {
            if(lastPos != sf::Mouse.getPosition() && spriteRect.contains(sf::Mouse::getPosition(window)));
            {
                lastPos = sf::Mouse.getPosition();
                object.setPosition(lastPos);
            }
            sf::IntRect spriteRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width,object.getGlobalBounds().height);
        }
        return false;
    }
}

#pragma once

#include "State.h"
#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace Tas
{
    class OptionMenuState : public State
    {
    public:
        OptionMenuState(GameDataRef data);
        void initState();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    private:
        GameDataRef _data;
        sf::Sprite _back_button;
        sf::Sprite _screen_size;
        sf::Sprite _background;
    };
}

#pragma once
#include "State.h"
#include <SFML/Graphics.hpp>
#include "Game.hpp"
namespace Tas
{
    class MainMenuState : public State
    {
        public:
        MainMenuState(GameDataRef data);

        void initState();
        void handleInput();
        void update(float dt);
        void draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _play_button;
        sf::Sprite _option_button;
        sf::Sprite _exit_button;
    };
}

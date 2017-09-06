#pragma once

#include "State.h"
#include "Game.hpp"
#include "Definitions.h"

namespace Tas
{
    class SplashState : public State
    {
    public:
        SplashState(GameDataRef data);

        void initState();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;
    };
}

#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Tas
{
    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        InputManager input;
        AssetManager assets;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        Game(sf::Vector2i w_size,std::string title);
    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;
        GameDataRef _data = std::make_shared<GameData>();

        void run();
    };
}

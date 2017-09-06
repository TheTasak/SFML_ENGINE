#include "Game.hpp"
#include "SplashState.hpp"

namespace Tas
{
    Game::Game(sf::Vector2i w_size, std::string title)
    {
        _data->window.create(sf::VideoMode(w_size.x,w_size.y), title, sf::Style::Close);
        _data->machine.addState(StateRef(new SplashState(this->_data)),true);
        this->run();
    }

    void Game::run()
    {
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;
        while(this->_data->window.isOpen())
        {
            this->_data->machine.proceedStateChanges();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if(frameTime > 0.25f)
                frameTime = 0.25f;
            currentTime = newTime;
            accumulator += frameTime;
            while(accumulator >= dt)
            {
                this->_data->machine.getActiveState()->handleInput();
                this->_data->machine.getActiveState()->update(dt);
                accumulator -= dt;
            }
            interpolation = accumulator / dt;
            this->_data->machine.getActiveState()->draw(interpolation);

        }
    }
}

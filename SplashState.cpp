#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "Game.hpp"
namespace Tas
{
    SplashState::SplashState(GameDataRef data) : _data(data){}
    void SplashState::initState()
    {
        this->_data->assets.loadTexture("SplashBack",SPLASH_BACK);
        _background.setTexture(this->_data->assets.getTexture("SplashBack"));
    }
    void SplashState::handleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                this->_data->window.close();
        }
    }
    void SplashState::update(float dt)
    {
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_SHOW_TIME)
        {
            this->_data->machine.addState(StateRef(new MainMenuState(_data)), true);
        }
    }
    void SplashState::draw(float dt)
    {
        this->_data->window.clear(sf::Color::White);
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }
}

#include "OptionMenuState.hpp"
#include "MainMenuState.hpp"
#include "Definitions.h"

namespace Tas
{
    OptionMenuState::OptionMenuState(GameDataRef data) : _data(data){}

    void OptionMenuState::initState()
    {
        //this->_data->assets.loadTexture("OptionBack", OPTIONMAIN_BACK);
        this->_data->assets.loadTexture("OptionBackButton", OPTIONMAIN_BACK_BUTTON);

        this->_back_button.setTexture(this->_data->assets.getTexture("OptionBackButton"));
        this->_screen_size.setTexture(this->_data->assets.getTexture("OptionBackButton"));

        this->_back_button.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (this->_back_button.getGlobalBounds().width / 2), SCREEN_HEIGHT / 3));
        this->_screen_size.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (this->_screen_size.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2));

    }
    void OptionMenuState::handleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                this->_data->window.close();
            if(this->_data->input.isSpriteClicked(this->_back_button,sf::Mouse::Left,this->_data->window))
                this->_data->machine.addState(StateRef(new MainMenuState(_data)), true);
            if(this->_data->input.isSpriteClicked(this->_screen_size,sf::Mouse::Left, this->_data->window))
                this->_data->window.setSize(sf::Vector2u(600,800));
        }
    }
    void OptionMenuState::update(float dt)
    {

    }
    void OptionMenuState::draw(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(_back_button);
        this->_data->window.draw(_screen_size);
        this->_data->window.display();
    }
}

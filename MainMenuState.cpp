#include "MainMenuState.hpp"
#include <sstream>
#include "Definitions.h"
#include "OptionMenuState.hpp"
#include <iostream>

namespace Tas
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data) {}

    void MainMenuState::initState()
    {
        //this->_data->assets.loadTexture("MainBack", MAINMENU_BACK);
        this->_data->assets.loadTexture("MainPlay", MAINMENU_PLAY);
        this->_data->assets.loadTexture("MainOption", MAINMENU_OPTIONS);
        this->_data->assets.loadTexture("MainExit", MAINMENU_EXIT);

        //this->_background.setTexture(this->_data->assets.getTexture("MainBack"));
        this->_play_button.setTexture(this->_data->assets.getTexture("MainPlay"));
        this->_option_button.setTexture(this->_data->assets.getTexture("MainOption"));
        this->_exit_button.setTexture(this->_data->assets.getTexture("MainExit"));

        this->_play_button.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (this->_play_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 5) * 2));
        this->_option_button.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (this->_option_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 5) * 3));
        this->_exit_button.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (this->_play_button.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 5) * 4));
    }

    void MainMenuState::handleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                this->_data->window.close();
            if(this->_data->input.isSpriteClicked(this->_play_button,sf::Mouse::Left,this->_data->window))
                std::cout << "Play button clicked" << std::endl;
            if(this->_data->input.isSpriteClicked(this->_option_button,sf::Mouse::Left,this->_data->window))
                this->_data->machine.addState(StateRef(new OptionMenuState(_data)),true);
            if(this->_data->input.isSpriteClicked(this->_exit_button,sf::Mouse::Left,this->_data->window))
                this->_data->window.close();
        }
    }
    void MainMenuState::update(float dt)
    {

    }
    void MainMenuState::draw(float dt)
    {
        this->_data->window.clear();
        //this->_data->window.draw(_background);
        this->_data->window.draw(_play_button);
        this->_data->window.draw(_option_button);
        this->_data->window.draw(_exit_button);

        this->_data->window.display();
    }
}

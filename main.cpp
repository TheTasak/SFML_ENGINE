#include <iostream>
#include "Game.hpp"
#include "Definitions.h"
int main()
{
    Tas::Game(sf::Vector2i(SCREEN_WIDTH,SCREEN_HEIGHT), "Engine");
    return 0;
}

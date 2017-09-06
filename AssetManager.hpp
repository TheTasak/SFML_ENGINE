#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Tas
{
    class AssetManager
    {
    public:
        void loadTexture(std::string name, std::string fileName);
        inline sf::Texture& getTexture(std::string name){return this->_textures.at(name);}

        void loadFont(std::string name, std::string fileName);
        inline sf::Font& getFont(std::string name){return this->_fonts.at(name);}

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}

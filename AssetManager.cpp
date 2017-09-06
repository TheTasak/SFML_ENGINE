#include "AssetManager.hpp"

namespace Tas
{
    void AssetManager::loadTexture(std::string name,std::string fileName)
    {
        sf::Texture tex;
        if(tex.loadFromFile("Assets/" + fileName))
        {
            this->_textures[name] = tex;
        }
    }
    void AssetManager::loadFont(std::string name,std::string fileName)
    {
        sf::Font fon;
        if(fon.loadFromFile("Assets/" + fileName))
        {
            this->_fonts[name] = fon;
        }
    }
}


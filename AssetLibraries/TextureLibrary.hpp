//
// Created by Zachary Buffone on 12/15/21.
//

#ifndef GARNET_ENGINE_TEXTURELIBRARY_HPP
#define GARNET_ENGINE_TEXTURELIBRARY_HPP

#include <string>
#include <map>
#include "../DataStructures/Texture.hpp"

namespace Garnet::AssetLibraries {

    class TextureLibrary {
    private:
        std::map<std::string, Texture*> textures;

        static Texture* CreateTextureFromFile(const std::string&);
    public:
        TextureLibrary();
        ~TextureLibrary();

        void LoadTexture(const std::string&, const std::string&);
        Texture* GetTexture(const std::string&);
    };

}


#endif //GARNET_ENGINE_TEXTURELIBRARY_HPP

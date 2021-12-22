//
// Created by Zachary Buffone on 12/15/21.
//

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

#include <system_error>
#include <filesystem>
#include "TextureLibrary.hpp"


namespace Garnet {

    AssetLibraries::TextureLibrary::TextureLibrary() {
        this->textures = std::map<std::string, Texture*>();
    }

    AssetLibraries::TextureLibrary::~TextureLibrary() {

    }

    void AssetLibraries::TextureLibrary::LoadTexture(const std::string& path, const std::string& name) {
        if(this->textures.find(name) != this->textures.end()) {
            throw std::runtime_error("Trying to load texture of name " + name + " when name already exists in library");
        }

        Texture* texture = CreateTextureFromFile(path);
        this->textures.insert(std::pair<std::string, Texture*>(name, texture));
    }

    Texture *AssetLibraries::TextureLibrary::GetTexture(const std::string& name) {
        if(this->textures.find(name) == this->textures.end()) {
            throw std::runtime_error("Texture of name " + name + " does not exist in library");
        }

        return textures.at(name);
    }

    Texture *AssetLibraries::TextureLibrary::CreateTextureFromFile(const std::string& path) {
        int width, height, n;
        auto string = std::filesystem::current_path().append(path).string();
        const char* path_cstr = string.c_str();
        unsigned char* data = stbi_load(path_cstr, &width, &height, &n, 0);

        Texture* texture = new Texture(data, width, height, n);

        return texture;
    }

}
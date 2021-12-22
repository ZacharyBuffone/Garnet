//
// Created by Zachary Buffone on 12/15/21.
//

#include "Texture.hpp"
#include "../Rendering/Renderer.hpp"

namespace Garnet {

    Garnet::Texture::Texture(unsigned char* d, int w, int h, int n) {
        this->data = d;
        this->width = w;
        this->height = h;
        this->numOfChannels = n;

        Rendering::Renderer::SetupTexture(this);
    }

    Garnet::Texture::~Texture() {
        delete[] this->data;
    }

    unsigned char* Texture::GetData() {
        return this->data;
    }

    int Texture::GetWidth() {
        return this->width;
    }

    int Texture::GetHeight() {
        return this->height;
    }

    int Texture::GetNumOfChannels() {
        return this->numOfChannels;
    }

}

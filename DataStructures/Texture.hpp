//
// Created by Zachary Buffone on 12/15/21.
//

#ifndef GARNET_ENGINE_TEXTURE_HPP
#define GARNET_ENGINE_TEXTURE_HPP

namespace Garnet {

    class Texture {
    private:
        unsigned char* data;
        int width, height, numOfChannels;

    public:
        unsigned int glIndex;

        Texture(unsigned char*, int, int, int);
        ~Texture();

        unsigned char* GetData();
        int GetWidth();
        int GetHeight();
        int GetNumOfChannels();

    };

}

#endif //GARNET_ENGINE_TEXTURE_HPP

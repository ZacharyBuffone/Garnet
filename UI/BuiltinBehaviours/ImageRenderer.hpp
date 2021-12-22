//
// Created by Zachary Buffone on 12/15/21.
//

#ifndef GARNET_ENGINE_IMAGERENDERER_HPP
#define GARNET_ENGINE_IMAGERENDERER_HPP

#include "../UIBehaviour.hpp"

namespace Garnet::UI {

    class ImageRenderer : public UIBehaviour {
    private:


    public:
        explicit ImageRenderer(UIObject* object);
        ~ImageRenderer();

    };

}

#endif //GARNET_ENGINE_IMAGERENDERER_HPP

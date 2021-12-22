//
// Created by Zachary Buffone on 12/15/21.
//


#ifndef GARNET_ENGINE_UI_HPP
#define GARNET_ENGINE_UI_HPP

#include <vector>
#include "UIObject.hpp"

namespace Garnet::UI {

    class UI {
    private:
        std::vector<UIObject*> uiObjects;

    public:
        UI();
        ~UI();

        void AddUIObject(UIObject*);

    };

}

#endif //GARNET_ENGINE_UI_HPP

//
// Created by Zachary Buffone on 12/15/21.
//

#include "UIObject.hpp"

namespace Garnet::UI {


    UIObject::UIObject() {
        this->behaviours = std::vector<UIBehaviour>();
    }

    UIObject::~UIObject() = default;

}

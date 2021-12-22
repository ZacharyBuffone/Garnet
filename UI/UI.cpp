//
// Created by Zachary Buffone on 12/15/21.
//

#include "UI.hpp"

namespace Garnet::UI {

    Garnet::UI::UI::UI() {
        this->uiObjects = std::vector<UIObject*>();
    }

    void UI::AddUIObject(UIObject* object) {
        this->uiObjects.push_back(object);
    }

    Garnet::UI::UI::~UI() = default;

}

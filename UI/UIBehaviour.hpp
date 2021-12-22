//
// Created by Zachary Buffone on 12/15/21.
//

#ifndef GARNET_ENGINE_UIBEHAVIOUR_HPP
#define GARNET_ENGINE_UIBEHAVIOUR_HPP

#include "UIObject.hpp"

namespace Garnet::UI {

    class UIObject;

    class UIBehaviour {
    private:
        UIObject* uiObject;

    public:
        UIBehaviour(UIObject*);
        ~UIBehaviour();

        virtual void Update() {}
        virtual void Draw() {}
    };

}


#endif //GARNET_ENGINE_UIBEHAVIOUR_HPP

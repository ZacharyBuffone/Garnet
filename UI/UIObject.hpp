//
// Created by Zachary Buffone on 12/15/21.
//

#ifndef GARNET_ENGINE_UIOBJECT_HPP
#define GARNET_ENGINE_UIOBJECT_HPP

#include <glm.hpp>
#include <vector>
#include "UIBehaviour.hpp"

namespace Garnet::UI {

    class UIBehaviour;

    class UIObject {
    private:
        std::vector<UIBehaviour> behaviours;

        glm::vec2 position;
        float rotation;
        glm::vec2 scale;

    public:
        UIObject();
        ~UIObject();

        template<typename T>
        UIBehaviour* AddBehaviour() {
            T* behaviour = T(this);
            this->behaviours.push_back((UIBehaviour)behaviour);
            return &behaviour;
        }

        template<typename T>
        UIBehaviour* GetBehaviour() {
            for(int i = 0; i < this->behaviours.size(); i++) {
                UIBehaviour& working = this->behaviours.at(i);
                if(dynamic_cast<T>(working)) {
                    return &working;
                }
            }

            return nullptr;
        }

    };

}

#endif //GARNET_ENGINE_UIOBJECT_HPP

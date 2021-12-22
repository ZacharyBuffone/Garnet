//
// Created by Zachary Buffone on 12/19/21.
//

#ifndef GARNET_ENGINE_CONSTANTROTATION_HPP
#define GARNET_ENGINE_CONSTANTROTATION_HPP

#include <vec3.hpp>
#include "../GameObject.hpp"

namespace Garnet {

    class ConstantRotation : Behaviour {
    private:
        glm::vec3 speed;

    public:
        ConstantRotation(GameObject* o);

        void Update() override;

        void Speed(const glm::vec3&);
        const glm::vec3& Speed();

    };

}

#endif //GARNET_ENGINE_CONSTANTROTATION_HPP

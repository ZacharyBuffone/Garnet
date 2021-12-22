//
// Created by Zachary Buffone on 12/19/21.
//

#ifndef GARNET_ENGINE_RAYCASTING_HPP
#define GARNET_ENGINE_RAYCASTING_HPP

#include <vec3.hpp>

struct RaycastHit {

};

class Raycasting {
public:
    static RaycastHit Raycast(glm::vec3 position, glm::vec3 direction, float maxDistance) {
        return {};
    }
};


#endif //GARNET_ENGINE_RAYCASTING_HPP

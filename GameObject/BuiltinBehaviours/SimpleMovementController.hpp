//
// Created by Zachary Buffone on 12/13/21.
//

#ifndef GARNET_ENGINE_SIMPLEMOVEMENTCONTROLLER_HPP
#define GARNET_ENGINE_SIMPLEMOVEMENTCONTROLLER_HPP

#include "../Behaviour.hpp"

namespace Garnet {

    class SimpleMovementController : public Behaviour {
    private:
        bool wPressed = false;
        bool aPressed = false;
        bool sPressed = false;
        bool dPressed = false;
        bool qPressed = false;
        bool ePressed = false;

        float speed = 5.0f;
        float rotationSpeed = 5.0f;

    public:
        SimpleMovementController(GameObject*);
        ~SimpleMovementController() = default;
        void Update() override;


    };

}


#endif //GARNET_ENGINE_SIMPLEMOVEMENTCONTROLLER_HPP

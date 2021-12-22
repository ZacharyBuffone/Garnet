//
// Created by Zachary Buffone on 12/13/21.
//

#include "SimpleMovementController.hpp"

#include "../../Input.hpp"
#include "../../Time.hpp"
#include "../../Mathf.hpp"

namespace Garnet {

    Garnet::SimpleMovementController::SimpleMovementController(GameObject* go) : Behaviour(go) {
        Input::SetKeyInputCallback(GLFW_KEY_W, [this](Input::KeyEvent ke) {
            this->wPressed = (bool) ke;
        });
        Input::SetKeyInputCallback(GLFW_KEY_A, [this](Input::KeyEvent ke) {
            this->aPressed = (bool) ke;
        });
        Input::SetKeyInputCallback(GLFW_KEY_S, [this](Input::KeyEvent ke) {
            this->sPressed = (bool) ke;
        });
        Input::SetKeyInputCallback(GLFW_KEY_D, [this](Input::KeyEvent ke) {
            this->dPressed = (bool) ke;
        });
        Input::SetKeyInputCallback(GLFW_KEY_Q, [this](Input::KeyEvent ke) {
            this->qPressed = (bool) ke;
        });
        Input::SetKeyInputCallback(GLFW_KEY_E, [this](Input::KeyEvent ke) {
            this->ePressed = (bool) ke;
        });
    }

    void SimpleMovementController::Update() {
        auto forward = gameObject->Forward() * (((float)wPressed * 1.0f) + ((float)sPressed * -1.0f)) * Time::DeltaTime();
        auto left = gameObject->Left() * (((float)aPressed * 1.0f) + ((float)dPressed * -1.0f)) * Time::DeltaTime();
        auto up = gameObject->Up() * (((float)ePressed * 1.0f) + ((float)qPressed * -1.0f)) * Time::DeltaTime();
        this->gameObject->SetPosition(this->gameObject->GetPosition() + ((left + forward + up) * this->speed) );

        auto mouseDelta = Input::MouseDelta();
        auto rotx = glm::angleAxis(mouseDelta.y * rotationSpeed * Time::DeltaTime(), this->gameObject->Left());
        auto roty = glm::angleAxis(-1.f * mouseDelta.x * rotationSpeed * Time::DeltaTime(), Mathf::vec3Up());

        this->gameObject->Rotate(rotx);
        this->gameObject->Rotate(roty);

        Behaviour::Update();
    }

}

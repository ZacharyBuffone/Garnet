//
// Created by Zachary Buffone on 12/7/21.
//

#include "Behaviour.hpp"

namespace Garnet {

    void Behaviour::Update() {}
    void Behaviour::Initialize() {}

    Behaviour::Behaviour(GameObject* gameObject) {
        this->gameObject = gameObject;
    }

    Behaviour::~Behaviour() = default;

    GameObject* Behaviour::GetGameObject() const {
        return this->gameObject;
    };


}
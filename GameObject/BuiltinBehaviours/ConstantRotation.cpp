//
// Created by Zachary Buffone on 12/19/21.
//

#include "ConstantRotation.hpp"
#include "../../Mathf.hpp"
#include "../../Time.hpp"

Garnet::ConstantRotation::ConstantRotation(GameObject* o) : Behaviour(o) {
    this->speed = Mathf::vec3Zero();
}

void Garnet::ConstantRotation::Update() {
    auto rotX = glm::angleAxis(this->speed.x * Time::DeltaTime(), Mathf::vec3Left());
    auto rotY = glm::angleAxis(this->speed.y * Time::DeltaTime(), Mathf::vec3Up());
    auto rotZ = glm::angleAxis(this->speed.z * Time::DeltaTime(), Mathf::vec3Forward());
    this->gameObject->Rotate(rotX * rotY * rotZ);
}

void Garnet::ConstantRotation::Speed(const glm::vec3& newSpeed) {
    this->speed = glm::vec3(newSpeed);
}

const glm::vec3 &Garnet::ConstantRotation::Speed() {
    return this->speed;
}

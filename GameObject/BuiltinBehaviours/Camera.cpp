//
// Created by Zachary Buffone on 12/9/21.
//

#include "Camera.hpp"
#include "../../Mathf.hpp"

namespace Garnet {

    Camera::Camera(Garnet::GameObject *go) : Behaviour(go)  {
        this->nearClipping = 0.1f;
        this->farClipping = 1000.0f;
        this->fov = 60;

        RecalculateProjectionMatrix();

        Camera::mainCamera = this;
    }

    Camera::~Camera() = default;

    glm::mat4 Camera::GetViewMatrix() {
//        auto view = glm::mat4(1.0f);
//        view = glm::translate(view, -1.0f * this->gameObject->GetPosition());
//        view = glm::rotate(view,angle(this->gameObject->GetRotation()), axis(this->gameObject->GetRotation()) * -1.0f);
//        return view;
        return glm::lookAt(
                this->gameObject->GetPosition(),
                this->gameObject->GetPosition() + this->gameObject->Forward(),
                this->gameObject->Up()
                );
    }

    void Camera::SetNearClipping(float value) {
        this->nearClipping = value;
        RecalculateProjectionMatrix();
    }

    void Camera::SetFarClipping(float value) {
        this->farClipping = value;
        RecalculateProjectionMatrix();
    }

    void Camera::SetFOV(float value) {
        this->fov = value;
        RecalculateProjectionMatrix();
    }

    float Camera::GetNearClipping() {
        return this->nearClipping;
    }

    float Camera::GetFarClipping() {
        return this->farClipping;
    }

    float Camera::GetFOV() {
        return this->fov;
    }

    const glm::mat4& Camera::GetProjectionMatrix() {
        return this->projectionMatrix;
    }

    void Camera::RecalculateProjectionMatrix() {
        this->projectionMatrix = glm::perspective(
                glm::radians(this->fov),
                1280.f/720.f,
                this->nearClipping,
                this->farClipping
                );
    }


}
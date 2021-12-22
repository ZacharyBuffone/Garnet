//
// Created by Zachary Buffone on 12/9/21.
//

#ifndef GARNET_ENGINE_CAMERA_HPP
#define GARNET_ENGINE_CAMERA_HPP

#include "../Behaviour.hpp"
#include "glm.hpp"

namespace Garnet {

    class Camera : public Behaviour {
    private:
        float nearClipping;
        float farClipping;
        float fov;

        glm::mat4 projectionMatrix;

        inline static Camera* mainCamera;

        inline void RecalculateProjectionMatrix();

    public:
        explicit Camera(Garnet::GameObject*);
        ~Camera();

        glm::mat4 GetViewMatrix();
        const glm::mat4& GetProjectionMatrix();


        void SetNearClipping(float);
        void SetFarClipping(float);
        void SetFOV(float);
        float GetNearClipping();
        float GetFarClipping();
        float GetFOV();

        static void SetMainCamera(Camera* camera) {
            mainCamera = camera;
        }

        static Camera& GetMainCamera() {
            return *mainCamera;
        }

    };

}

#endif //GARNET_ENGINE_CAMERA_HPP

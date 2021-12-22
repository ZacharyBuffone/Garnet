//
// Created by Zachary Buffone on 12/13/21.
//

#include "Input.hpp"
#include "Rendering/Renderer.hpp"
#include <functional>
#include <iostream>

namespace Garnet{

    void Input::SetKeyInputCallback(int key, const KeyInputCallback& callback) {
        if(keyCallbacks.find(key) == keyCallbacks.end()) {
            keyCallbacks.insert(std::pair<int, std::vector<KeyInputCallback>>(key, std::vector<KeyInputCallback>()));
        }

        keyCallbacks.at(key).push_back(callback);
    }

    void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if(keyCallbacks.find(key) != keyCallbacks.end()) {
            auto& vec = keyCallbacks.at(key);
            for(auto & func : vec) {
                func((KeyEvent)action);
            }
        }
    }

    void Input::Initialize() {
        keyCallbacks = std::map<int, std::vector<KeyInputCallback>>();
        glfwSetKeyCallback(Garnet::Rendering::Renderer::GetWindow(), Input::KeyCallback);
    }

    const glm::vec2& Input::MousePos() {
        return mousePos;
    }

    const glm::vec2& Input::MouseDelta() {
        return mouseDelta;
    }

    void Input::Update() {
        double x, y;
        glfwGetCursorPos(Garnet::Rendering::Renderer::GetWindow(), &x, &y);
        auto pos = glm::vec2(x, y);
        mouseDelta = pos - mousePos;
        mousePos = pos;
        std::cout << mouseDelta.x << ", " << mouseDelta.y << std::endl;

    }

}

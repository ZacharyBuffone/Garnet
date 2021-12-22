//
// Created by Zachary Buffone on 12/13/21.
//

#ifndef GARNET_ENGINE_INPUT_HPP
#define GARNET_ENGINE_INPUT_HPP

#include <glfw3.h>
#include <map>
#include <vector>
#include <functional>
#include <glm.hpp>


namespace Garnet {

    class Input {
    public:
        enum KeyEvent { Released, Pressed };
        typedef std::function<void(KeyEvent)> KeyInputCallback;



    private:
        inline static std::map<int, std::vector<KeyInputCallback>> keyCallbacks;
        static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void CursorPosCallback(GLFWwindow* window, double x, double y);
        inline static glm::vec2 mousePos = glm::vec2(0.f, 0.f);
        inline static glm::vec2 mouseDelta = glm::vec2(0.f, 0.f);
    public:
        static void SetKeyInputCallback(int key, const KeyInputCallback&);
        static void Initialize();
        static void Update();
        static const glm::vec2& MousePos();
        static const glm::vec2& MouseDelta();
    };

}

#endif //GARNET_ENGINE_INPUT_HPP

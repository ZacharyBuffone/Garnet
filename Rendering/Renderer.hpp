//
// Created by Zachary Buffone on 12/7/21.
//

#ifndef GARNET_ENGINE_RENDERER_HPP
#define GARNET_ENGINE_RENDERER_HPP

#include <glfw3.h>
#include <OpenGL/gl3.h>
#include <glm.hpp>
#include "../GameObject/BuiltinBehaviours/MeshRenderer.hpp"
#include "../DataStructures/Shader.hpp"
#include "../DataStructures/Texture.hpp"
#include "../GameObject/BuiltinBehaviours/MeshContainer.hpp"


namespace Garnet::Rendering {
    class Renderer {
    private:
        inline static GLFWwindow* window;
    public:
        static void Initialize();
        static void Terminate();
        static void Clear();
        static void PushBuffer();

        static GLFWwindow* GetWindow();

        static void DrawMeshRenderer(const MeshRenderer&, const MeshContainer&);
        static void SetupMesh(Mesh&);

        static unsigned int SetupShader(Shader*);
        static void SetupTexture(Texture*);
    };

}


#endif //GARNET_ENGINE_RENDERER_HPP

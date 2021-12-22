//
// Created by Zachary Buffone on 12/7/21.
//



#include <glm.hpp>
#include <vector>
#include <gtc/type_ptr.hpp>
#include <iostream>
#include <glfw3.h>
#include "Renderer.hpp"
#include "../GameObject/BuiltinBehaviours/Camera.hpp"
#include "../DataStructures/Texture.hpp"

namespace Garnet::Rendering {

    unsigned int programIndex = -1;

    void Renderer::Initialize() {

        //Initialize GLFW Library
        if(!glfwInit())
            throw new std::runtime_error("Failed initializing GLFW.");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        //Create window and context
        Renderer::window = glfwCreateWindow(1280, 720, "Garnet Engine", nullptr, nullptr);
        if(!Renderer::window)
        {
            //NULL will be returned if creation fails
            glfwTerminate();
            throw std::runtime_error("GLFW failed to instantiate window.");

        }
        //Establish the context of the current window
        glfwMakeContextCurrent(Renderer::window);

        auto* version = glGetString(GL_VERSION);
        auto* glslversion = glGetString(GL_SHADING_LANGUAGE_VERSION);
        std::cout << "GL version " << version << std::endl;
        std::cout << "GLSL version " << glslversion << std::endl;

        glEnable(GL_DEPTH_TEST);
        //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    }


    void Renderer::Clear() {
        glClearColor(0.2, 0.3, 0.3, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glClear(GL_COLOR_BUFFER_BIT);

        //set uniforms
        int projectionLoc = glGetUniformLocation(6, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(Camera::GetMainCamera().GetProjectionMatrix()));
        int viewLoc = glGetUniformLocation(6, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(Camera::GetMainCamera().GetViewMatrix()));
    }

    void Renderer::PushBuffer() {
        glfwSwapBuffers(Renderer::window);
    }

    void Renderer::DrawMeshRenderer(const MeshRenderer& mr, const MeshContainer& mc) {
        auto* mesh = mc.GetMesh();
        auto* material = mr.GetMaterial();

        glUseProgram(material->GetShader()->GetProgramIndex());

        for(auto& name : material->GetTexturePropertyNames()) {
            glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
            glBindTexture(GL_TEXTURE_2D, material->GetTextureProperty(name)->glIndex);
        }

        int modelLoc = glGetUniformLocation(3, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(mr.GetGameObject()->GetWorldModelMatrix()));
        // draw mesh
        glBindVertexArray(mesh->vao);
        glDrawElements(GL_TRIANGLES, mesh->GetTriangles().size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    void Renderer::SetupMesh(Mesh& mesh) {
        auto& vertices = mesh.GetVertices();
        auto& triangles = mesh.GetTriangles();

        glGenVertexArrays(1, &mesh.vao);
        glGenBuffers(1, &mesh.vbo);
        glGenBuffers(1, &mesh.ebo);

        glBindVertexArray(mesh.vao);
        glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(MeshVertex), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangles.size() * sizeof(unsigned int),
                     &triangles[0], GL_STATIC_DRAW);

        // vertex positions
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, position));
        glEnableVertexAttribArray(0);
        // vertex normals
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, normal));
        glEnableVertexAttribArray(1);
        // vertex texture coords
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, uv));
        glEnableVertexAttribArray(2);
        // vertex color
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (void*)offsetof(MeshVertex, color));
        glEnableVertexAttribArray(3);

        glBindVertexArray(0);
    }

    void Renderer::Terminate() {
        glfwTerminate();
    }

    unsigned int Renderer::SetupShader(Shader* shader) {
        int success;
        char infoLog[512];

        auto& vertStr = shader->GetVertCode();
        auto& fragStr = shader->GetFragCode();

        auto* vertCStr = vertStr.c_str();
        auto* fragCStr = fragStr.c_str();

        unsigned int vert = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vert, 1, &vertCStr, 0);
        glCompileShader(vert);
        glGetShaderiv(vert, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(vert, 512, 0, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        unsigned int frag = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(frag, 1, &fragCStr, 0);
        glCompileShader(frag);
        glGetShaderiv(frag, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(frag, 512, 0, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }


        delete[] vertCStr;
        delete[] fragCStr;

        unsigned int prog = glCreateProgram();
        glAttachShader(prog, vert);
        glAttachShader(prog, frag);
        glLinkProgram(prog);
        glGetProgramiv(prog, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(prog, 512, 0, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        glDeleteShader(vert);
        glDeleteShader(frag);

        return prog;
    }

    GLFWwindow *Renderer::GetWindow() {
        return Renderer::window;
    }

    void Renderer::SetupTexture(Texture* texture) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glGenTextures(1, &(texture->glIndex));
        glBindTexture(GL_TEXTURE_2D, texture->glIndex);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->GetWidth(), texture->GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->GetData());
        glGenerateMipmap(GL_TEXTURE_2D);


    }

}
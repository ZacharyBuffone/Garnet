//
// Created by Zachary Buffone on 12/7/21.
//

#include "GarnetEngine.hpp"
#include "AssetLibraries/ShaderLibrary.hpp"
#include "Time.hpp"
#include "Input.hpp"

namespace Garnet {

    GarnetEngine* GarnetEngine::instance = nullptr;

    GarnetEngine::GarnetEngine() {
        Rendering::Renderer::Initialize();
        Time::Initialize();
        Input::Initialize();
        this->currentScene = nullptr;
        this->running = false;
        this->meshLibrary = new AssetLibraries::MeshLibrary();
        this->shaderLibrary = new AssetLibraries::ShaderLibrary();
        this->textureLibrary = new AssetLibraries::TextureLibrary();
    }

    GarnetEngine::~GarnetEngine() = default;

    void GarnetEngine::Start() {
        this->running = true;
        while(this->running && !glfwWindowShouldClose(Rendering::Renderer::GetWindow())) {
            glfwPollEvents();
            Time::Update();
            Input::Update();
            Rendering::Renderer::Clear();
            this->currentScene->Update();
            this->currentScene->Draw();
            Rendering::Renderer::PushBuffer();
        }

        GarnetEngine::Terminate();
    }

    void GarnetEngine::Stop() {
        this->running = false;
    }

    void GarnetEngine::SetCurrentScene(Scene* scene) {
        this->currentScene = scene;
    }

    Scene& GarnetEngine::GetCurrentScene() {
        return *(this->currentScene);
    }

    AssetLibraries::MeshLibrary& GarnetEngine::GetMeshLibrary() {
        return *(this->meshLibrary);
    }

    AssetLibraries::ShaderLibrary &GarnetEngine::GetShaderLibrary() {
        return *(this->shaderLibrary);
    }

    AssetLibraries::TextureLibrary& GarnetEngine::GetTextureLibrary() {
        return *(this->textureLibrary);
    }

    void GarnetEngine::Terminate() {
        delete GarnetEngine::instance;
    }

    GarnetEngine &GarnetEngine::GetEngine() {
        return *GarnetEngine::instance;
    }

    void GarnetEngine::Initialize() {
        if(GarnetEngine::instance != nullptr)
            throw std::runtime_error("More that one instance of GarnetEngine trying to be run! Duplicate GarnetEngine::Initialize() calls?");
        GarnetEngine::instance = new GarnetEngine();
    }

}
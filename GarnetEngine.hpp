//
// Created by Zachary Buffone on 12/7/21.
//

#ifndef GARNET_ENGINE_GARNETENGINE_HPP
#define GARNET_ENGINE_GARNETENGINE_HPP

#include <OpenGL/gl.h>

#include "Rendering/Renderer.hpp"
#include "Scene.hpp"
#include "AssetLibraries/MeshLibrary.hpp"
#include "AssetLibraries/ShaderLibrary.hpp"
#include "AssetLibraries/TextureLibrary.hpp"


namespace Garnet {

    class GarnetEngine {
    private:
        AssetLibraries::MeshLibrary* meshLibrary;
        AssetLibraries::ShaderLibrary* shaderLibrary;
        AssetLibraries::TextureLibrary* textureLibrary;
        Scene* currentScene;
        bool running;
        static GarnetEngine* instance;

    public:
        GarnetEngine();
        ~GarnetEngine();

        void Start();
        void Stop();

        void SetCurrentScene(Scene*);
        Scene& GetCurrentScene();

        AssetLibraries::MeshLibrary& GetMeshLibrary();
        AssetLibraries::ShaderLibrary& GetShaderLibrary();
        AssetLibraries::TextureLibrary& GetTextureLibrary();

        static void Initialize();

        static GarnetEngine& GetEngine();

        static void Terminate();

    };

}


#endif //GARNET_ENGINE_GARNETENGINE_HPP

//
// Created by Zachary Buffone on 12/7/21.
//

#ifndef GARNET_ENGINE_SCENE_HPP
#define GARNET_ENGINE_SCENE_HPP


#include "GameObject/GameObject.hpp"
#include <vector>
#include "UI/UI.hpp"

namespace Garnet {

    class Scene {
    private:
        std::vector<GameObject *>* gameObjects;
        UI::UI* ui;

    public:
        Scene();
        ~Scene();

        void Update();
        void Draw();

        void AddGameObject(GameObject *go);
        void DestroyGameObject(GameObject *go);

        UI::UI* GetUI();

    };
}


#endif //GARNET_ENGINE_SCENE_HPP

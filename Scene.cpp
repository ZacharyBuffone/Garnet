//
// Created by Zachary Buffone on 12/7/21.
//

#include "Scene.hpp"

namespace Garnet {

    Scene::Scene() {
        this->gameObjects = new std::vector<GameObject*>();
        this->ui = new UI::UI();
    }

    Scene::~Scene() {
        delete gameObjects;
    }

    void Scene::Update() {
        for(int i = 0; i < this->gameObjects->size(); i++) {
            gameObjects->at(i)->Update();
        }
    }

    void Scene::Draw() {
        for(auto & gameObject : *gameObjects) {
            gameObject->Draw();
        }
    }

    void Scene::AddGameObject(GameObject* go) {
        gameObjects->push_back(go);
    }

    void Scene::DestroyGameObject(GameObject* go)  {
        //find gameobject index
        int index = -1;
        for(int i = 0; i < this->gameObjects->size(); i++) {
            if(gameObjects->at(i) == go) {
                index = i;
                break;
            }
        }

        if(index == -1) //go was not found, silently fail
            return;

        gameObjects->erase(gameObjects->begin() + index);
    }

    UI::UI* Scene::GetUI() {
        return this->ui;
    }

}
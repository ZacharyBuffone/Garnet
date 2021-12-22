//
// Created by Zachary Buffone on 12/7/21.
//

#ifndef GARNET_ENGINE_GAMEOBJECT_HPP
#define GARNET_ENGINE_GAMEOBJECT_HPP

#include "Behaviour.hpp"
#include <string>
#include <vector>
#include <glm.hpp>
#include <gtc/quaternion.hpp>


namespace Garnet {
    class Behaviour;

    class GameObject {
    private:
        std::string name;
        glm::vec3 position{};
        glm::quat rotation{};
        glm::vec3 scale{};

        unsigned int layer;
        std::vector<std::string> tags;

        glm::mat4 modelMatrix{};

        std::vector<Behaviour*>* behaviours;

        GameObject* parent;
        std::vector<GameObject*> children;

        void RecalculateModelMatrix();

    public:
        GameObject(const std::string& = "New GameObject", const glm::vec3& pos = glm::vec3(0.f, 0.f, 0.f), const glm::quat& rot = glm::quat(1.f, 0.f, 0.f, 0.f), const glm::vec3& scale = glm::vec3(1.f, 1.f, 1.f));
        ~GameObject();

        const glm::vec3& GetPosition();
        const glm::quat& GetRotation();
        const glm::vec3& GetScale();
        const glm::mat4& GetModelMatrix();
        void SetPosition(const glm::vec3&);
        void SetRotation(const glm::quat&);
        void SetScale(const glm::vec3&);

        void Rotate(const glm::quat&);

        glm::vec3 Forward();
        glm::vec3 Up();
        glm::vec3 Left();

        glm::vec3 EulerAngles();

        void SetParent(GameObject*);
        GameObject* GetParent();
        const std::vector<GameObject*>& GetChildren();
        GameObject* GetChildAtIndex(int);
        unsigned int GetChildCount();

        void SetLayer(unsigned int);
        unsigned int GetLayer() const;

        void AddTag(const std::string&);
        void RemoveTag(const std::string&);
        const std::vector<std::string>& GetTags();

        glm::mat4 LocalToWorldMatrix();

        glm::mat4 GetWorldModelMatrix();

        template<typename T>
        T* GetBehaviour() {
            Behaviour* b = nullptr;
            for(int i = 0; i < this->behaviours->size(); i++) {
                Behaviour* working = this->behaviours->at(i);
                if(dynamic_cast<T*>(working)) {
                    b = working;
                }
            }

            return (T*)b;
        }

        template <typename T>
        T* AddBehaviour() {
            T* b = new T(this);
            this->behaviours->push_back((Behaviour*) b);
            return b;
        }

        virtual void Update();
        virtual void Draw();



    };

}

#endif //GARNET_ENGINE_GAMEOBJECT_HPP

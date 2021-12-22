//
// Created by Zachary Buffone on 12/7/21.
//

#include "GameObject.hpp"
#include "../Mathf.hpp"
#include "Drawable.hpp"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace Garnet {

    GameObject::GameObject(const std::string& name, const glm::vec3& pos, const glm::quat& rot, const glm::vec3& scale) {
        this->name = name;
        this->position = pos;
        this->rotation = rot;
        this->scale = scale;
        this->parent = nullptr;

        this->layer = 0x1;                            //0x1 is default layer
        this->tags = std::vector<std::string>();

        this->behaviours = new std::vector<Behaviour*>();

        RecalculateModelMatrix();
    }

    GameObject:: ~GameObject() = default;

    const glm::vec3& GameObject::GetPosition() {
        return this->position;
    }
    const glm::quat& GameObject::GetRotation() {
        return this->rotation;
    }
    const glm::vec3& GameObject::GetScale() {
        return this->scale;
    }

    void GameObject::SetPosition(const glm::vec3& vec) {
        this->position = glm::vec3(vec);
        RecalculateModelMatrix();
    }
    void GameObject::SetRotation(const glm::quat& quat) {
        this->rotation = glm::quat(quat);
        RecalculateModelMatrix();
    }
    void GameObject::SetScale(const glm::vec3& vec) {
        this->scale = glm::vec3(vec);
        RecalculateModelMatrix();
    }

    void GameObject::Update() {
        for(int i = 0; i < behaviours->size(); i++) {
            behaviours->at(i)->Update();
        }
    }

    const glm::mat4 &GameObject::GetModelMatrix() {
        return this->modelMatrix;
    }

    void GameObject::RecalculateModelMatrix() {
        this->modelMatrix = glm::mat4(1.f);
        this->modelMatrix = glm::translate(this->modelMatrix, this->position);
        this->modelMatrix = glm::rotate(this->modelMatrix, angle(this->rotation), axis(this->rotation));
        this->modelMatrix = glm::scale(this->modelMatrix, this->scale);
    }

    void GameObject::Draw() {
        for(int i = 0; i < behaviours->size(); i++) {
            auto* drawable = dynamic_cast<Drawable*>(behaviours->at(i));
            if(drawable) {
                drawable->Draw();
            }
        }
    }

    void GameObject::Rotate(const glm::quat& rot) {
        this->rotation = rot * this->rotation;
        this->RecalculateModelMatrix();
    }

    glm::vec3 GameObject::Forward() {
        return this->rotation * Mathf::vec3Forward();
    }

    glm::vec3 GameObject::Up() {
        return this->rotation * Mathf::vec3Up();
    }

    glm::vec3 GameObject::Left() {
        return this->rotation * Mathf::vec3Left();
    }

    glm::vec3 GameObject::EulerAngles() {
        return glm::eulerAngles(this->rotation);
    }

    void GameObject::SetParent(GameObject* p) {
        this->parent = p;
        p->children.push_back(this);
    }

    GameObject *GameObject::GetParent() {
        return this->parent;
    }

    const std::vector<GameObject *> &GameObject::GetChildren() {
        return this->children;
    }

    GameObject *GameObject::GetChildAtIndex(int index) {
        return this->children.at(index);
    }

    unsigned int GameObject::GetChildCount() {
        return this->children.size();
    }

    unsigned int GameObject::GetLayer() const {
        return this->layer;
    }

    void GameObject::SetLayer(unsigned int layer) {
        this->layer = layer;
    }

    void GameObject::AddTag(const std::string& tag) {
        this->tags.emplace_back(std::string(tag));
    }

    void GameObject::RemoveTag(const std::string & tag) {
        auto end = std::remove_if(this->tags.begin(), this->tags.end(), [tag](std::string& t) {return t.compare(tag);} );
        this->tags.erase(end, this->tags.end());
    }

    const std::vector<std::string>& GameObject::GetTags() {
        return this->tags;
    }

    glm::mat4 GameObject::LocalToWorldMatrix() {
        GameObject* current = this->parent;
        glm::mat4 matrix = glm::mat4(1.f);
        while(current != nullptr) {
            matrix = current->GetModelMatrix() * matrix;
            current = current->parent;
        }

        return matrix;
    }

    glm::mat4 GameObject::GetWorldModelMatrix() {
        return LocalToWorldMatrix() * modelMatrix;
    }

}

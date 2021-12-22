//
// Created by Zachary Buffone on 12/11/21.
//

#include "Material.hpp"

namespace Garnet {

    Material::Material() {
        this->shader = nullptr;
        this->floatProperties = std::map<std::string, MaterialPropertyFloat>();
        this->texProperties = std::map<std::string, MaterialPropertyTex>();
    }

    Material::Material(Shader* shader) {
        this->shader = shader;
    }

    Material::~Material() = default;

    Shader* Material::GetShader() {
        return this->shader;
    }
    void Material::SetShader(Shader* shader) {
        this->shader = shader;
    }

    floatvec Material::GetFloatProperty(const std::string& name) {
        return this->floatProperties.at(name).value;
    }

    Texture *Material::GetTextureProperty(const std::string& name) {
        return this->texProperties.at(name).texture;
    }

    void Material::SetFloatProperty(const std::string& name, floatvec value) {
        this->floatProperties.at(name).value = value;
    }

    void Material::SetTextureProperty(const std::string& name, Texture* tex) {
        this->texProperties.at(name).texture = tex;
    }

    void Material::AddFloatProperty(const std::string& name, MaterialPropertyType type, floatvec value) {
        this->floatProperties.insert(std::pair<std::string, MaterialPropertyFloat>(std::string(name), { type, value }));
    }

    void Material::AddTextureProperty(const std::string& name, MaterialPropertyType type, Texture* texture) {
        this->texProperties.insert(std::pair<std::string, MaterialPropertyTex>(std::string(name), { type, texture }));
    }

    std::vector<std::string> Material::GetTexturePropertyNames() {
        auto vec = std::vector<std::string>();
        for(const auto& prop : this->texProperties) {
            vec.emplace_back(std::string(prop.first));
        }

        return vec;
    }

}

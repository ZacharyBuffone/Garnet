//
// Created by Zachary Buffone on 12/11/21.
//

#ifndef GARNET_ENGINE_MATERIAL_HPP
#define GARNET_ENGINE_MATERIAL_HPP

#include <cstddef>

#include <glm.hpp>
#include <string>
#include <map>
#include <vector>
#include "Shader.hpp"
#include "Texture.hpp"

namespace Garnet {

    enum MaterialPropertyType {
        float1, float3, float2, tex2d, normmap
    };

    union floatvec {
        float float1;
        glm::vec2 float2;
        glm::vec3 float3;
    };

    struct MaterialPropertyFloat {
        MaterialPropertyType type;
        floatvec value;
    };

    struct MaterialPropertyTex {
        MaterialPropertyType type;
        Texture* texture;
    };

    class Material {
    private:
        std::map<std::string, MaterialPropertyFloat> floatProperties;
        std::map<std::string, MaterialPropertyTex> texProperties;

        Shader *shader;

    public:
        Material();
        explicit Material(Shader *shader);
        ~Material();


        Shader* GetShader();
        void SetShader(Shader*);
        floatvec GetFloatProperty(const std::string&);
        Texture* GetTextureProperty(const std::string&);
        void SetFloatProperty(const std::string&, floatvec);
        void SetTextureProperty(const std::string&, Texture*);
        void AddFloatProperty(const std::string&, MaterialPropertyType, floatvec);
        void AddTextureProperty(const std::string&, MaterialPropertyType, Texture*);

        std::vector<std::string> GetTexturePropertyNames();

    };

}

#endif //GARNET_ENGINE_MATERIAL_HPP

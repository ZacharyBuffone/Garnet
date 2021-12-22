//
// Created by Zachary Buffone on 12/12/21.
//

#ifndef GARNET_ENGINE_SHADERLIBRARY_HPP
#define GARNET_ENGINE_SHADERLIBRARY_HPP

#include <map>
#include <string>
#include "../DataStructures/Shader.hpp"

namespace Garnet::AssetLibraries {

    class ShaderLibrary {
    private:
        std::map<std::string, Shader*>* shaders;

        static Shader* CreateShaderFromFile(const std::string&, const std::string&);
    public:
        ShaderLibrary();
        ~ShaderLibrary();

        void LoadShader(const std::string&, const std::string&, const std::string&);
        Shader* GetShader(const std::string&);
    };

}


#endif //GARNET_ENGINE_SHADERLIBRARY_HPP

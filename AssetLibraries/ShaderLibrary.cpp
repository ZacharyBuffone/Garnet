//
// Created by Zachary Buffone on 12/12/21.
//

#include "ShaderLibrary.hpp"
#include <fstream>
#include <filesystem>
#include <sstream>

namespace Garnet::AssetLibraries {

    ShaderLibrary::ShaderLibrary() {
        this->shaders = new std::map<std::string, Shader*>();
    }

    ShaderLibrary::~ShaderLibrary() {
    }

    void ShaderLibrary::LoadShader(const std::string& vertPath, const std::string& fragPath, const std::string& name) {
        if(!(this->shaders->find(name) == this->shaders->end()))
            throw std::runtime_error("Trying to load a shader when mesh with name given already exists;");

        Shader* shader = this->CreateShaderFromFile(vertPath, fragPath);
        shaders->insert(std::pair<std::string, Shader*>(name, shader));
    }

    Shader* ShaderLibrary::GetShader(const std::string& name) {
        return this->shaders->at(name);
    }

    Shader* ShaderLibrary::CreateShaderFromFile(const std::string& vertPath, const std::string& fragPath) {
        auto vertStream = std::ifstream(std::filesystem::current_path().append(vertPath));
        auto fragStream = std::ifstream(std::filesystem::current_path().append(fragPath));

        if(!vertStream || !fragStream)
            throw std::runtime_error("Error loading either frag file or vert file of shader.");

        auto vertss = std::ostringstream();
        auto fragss = std::ostringstream();

        vertss << vertStream.rdbuf(); // reading data
        auto vertString = vertss.str();

        fragss << fragStream.rdbuf(); // reading data
        auto fragString = fragss.str();


        auto* shader = new Shader(vertString, fragString);

        return shader;
    }

}

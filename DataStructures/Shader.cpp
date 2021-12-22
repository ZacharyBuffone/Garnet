//
// Created by Zachary Buffone on 12/12/21.
//

#include "Shader.hpp"
#include "../Rendering/Renderer.hpp"

namespace Garnet {

    Garnet::Shader::Shader() {
        this->vertCode = std::string("");
        this->fragCode = std::string("");
    }

    Garnet::Shader::Shader(std::string& vertCode, std::string& fragCode) {
        this->vertCode = std::string(vertCode);
        this->fragCode = std::string(fragCode);

        this-> programIndex = Rendering::Renderer::SetupShader(this);
    }


    const std::string& Shader::GetVertCode() const {
        return this->vertCode;
    }

    const std::string& Shader::GetFragCode() const {
        return this->fragCode;
    }

    unsigned int Shader::GetProgramIndex() const {
        return this->programIndex;
    }

    Garnet::Shader::~Shader() = default;

}

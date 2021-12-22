//
// Created by Zachary Buffone on 12/12/21.
//

#ifndef GARNET_ENGINE_SHADER_HPP
#define GARNET_ENGINE_SHADER_HPP

#include <string>

namespace Garnet {
    class Shader {
    private:
        std::string vertCode;
        std::string fragCode;

        unsigned int programIndex;

    public:
        Shader();
        explicit Shader(std::string& vertCode, std::string& fragCode);
        ~Shader();

        unsigned int GetProgramIndex() const;

        const std::string& GetVertCode() const;
        const std::string& GetFragCode() const;
    };
}


#endif //GARNET_ENGINE_SHADER_HPP

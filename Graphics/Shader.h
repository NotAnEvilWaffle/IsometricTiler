//
// Created by gabrielt on 4/23/24.
//

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
    unsigned int shaderProgram;

    Shader(const char *vertexShaderPath, const char *fragmentShaderPath);

    void Use() const;
    void Compile(const char *vertSouce, const char *fragSource);

    void SetInt(const std::string &name, int value);
    void SetFloat(const std::string &name, float value);
    void SetVec3f(const std::string &name, const glm::vec3 &vec);
    void SetMat4(const std::string &name, const glm::mat4 &mat);
};

#endif // SHADER_H

#include "Shader.h"
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <glad/glad.h>

Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    std::string vertSource, fragSource;
    std::ifstream vertFile, fragFile;

    try
    {
        vertFile.open(vertexShaderPath);
        fragFile.open(fragmentShaderPath);

        vertSource.assign(std::istreambuf_iterator<char>(vertFile), std::istreambuf_iterator<char>());
        fragSource.assign(std::istreambuf_iterator<char>(fragFile), std::istreambuf_iterator<char>());

        vertFile.close();
        fragFile.close();
    }
    catch (std::ifstream::failure &e)
    {
        std::cout << "ERROR::SHADER::FILE_CANNOT_BE_READ" << std::endl;
        std::cout << e.what() << std::endl;
    }
    const char *vertCode = vertSource.c_str();
    const char *fragCode = fragSource.c_str();

    Compile(vertCode, fragCode);
}

void Shader::Compile(const char *vertSource, const char *fragSource)
{
    int success;
    char infoLog[512];
    unsigned int vertID, fragID;
    shaderProgram = glCreateProgram();

    vertID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertID, 1, &vertSource, nullptr);
    glCompileShader(vertID);
    glGetShaderiv(vertID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertID, 512, nullptr, infoLog);
        std::cout << "ERROR:SHADER::VERTEX::COMPILATION_ERROR\n"
                  << infoLog << std::endl;
    }

    fragID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragID, 1, &fragSource, nullptr);
    glCompileShader(fragID);
    glGetShaderiv(fragID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragID, 512, nullptr, infoLog);
        std::cout << "ERROR:SHADER::FRAGMENT::COMPILATION_ERROR\n"
                  << infoLog << std::endl;
    }

    glAttachShader(shaderProgram, vertID);
    glAttachShader(shaderProgram, fragID);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }

    glDeleteShader(vertID);
    glDeleteShader(fragID);
}

void Shader::Use() const
{
    glUseProgram(this->shaderProgram);
}

void Shader::SetInt(const std::string &name, int value)
{
    glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value)
{
    glUniform1f(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}

void Shader::SetVec3f(const std::string &name, const glm::vec3 &vec)
{
    glUniform3f(glGetUniformLocation(this->shaderProgram, name.c_str()), vec.x, vec.y, vec.z);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &mat)
{
    glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

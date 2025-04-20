#version 330 core
layout (location = 0) in vec4 vertPosTex;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
  TexCoords = vertPosTex.zw;
  gl_Position = projection * view * model * vec4(vertPosTex.xy, 0.0, 1.0);
}

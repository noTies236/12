#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aCoord;

out vec3 fragColor;
out vec3 test;
out vec2 TextCoord;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    fragColor = aPos;
    test = aPos;
    TextCoord = aCoord;
}
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aCoord;

out vec3 fragColor;
out vec3 test;
out vec2 TextCoord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    fragColor = aColor;
    test = aPos;
    TextCoord = aCoord;
}
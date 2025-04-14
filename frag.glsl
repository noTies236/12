#version 330 core

in vec3 fragColor;
in vec2 TextCoord;

uniform sampler2D ourText;

out vec4 color;

void main()
{
    color = texture(ourText, TextCoord);
}
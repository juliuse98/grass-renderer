#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 offset;

uniform mat4 u_MVP;

void main() {
    gl_Position = u_MVP * vec4(position + offset, 1.0f);
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

void main() {
    color = vec4(vec3(0.0f, 0.14f, 0.06f),1.0f);
};
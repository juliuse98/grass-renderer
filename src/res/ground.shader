#shader vertex
#version 330 core

float distSquared(vec3 A, vec3 B)
{

    vec3 C = A - B;
    return dot(C, C);

}

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 offset;

const float density = 0.003f;
const float gradient = 5.0f;

uniform mat4 u_MVP;
uniform vec3 cameraPos;

out float v_visibility;

void main() {
    vec3 bladePosition = position + offset;
    float v = sqrt(distSquared(cameraPos, bladePosition));
    v = exp(-pow(v * density, gradient));
    v = clamp(v, 0.0f, 1.0f);
    v_visibility = v;
    gl_Position = u_MVP * vec4(bladePosition, 1.0f);
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in float v_visibility;

void main() {
    color = vec4(vec3(0.0f, 0.14f, 0.06f) , 1.0f);
    color = mix(vec4(200.0f / 255.0f, 230.0f / 255.0f, 240.0f / 255.0f, 1.0f), color, v_visibility);
};
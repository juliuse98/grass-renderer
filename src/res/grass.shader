#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 offset;
layout(location = 2) in vec3 chunkOffset;


uniform mat4 u_MVP;
uniform float u_rotations[16];
uniform float u_time;
uniform vec3 u_wind_direction;
uniform float u_y_scale;

out vec3 v_position;

vec3 rotateVec3(vec3 v, vec3 axis, float angle)
{
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);
    float oneMinusCosAngle = 1.0 - cosAngle;

    mat3 rotationMatrix = mat3(
        cosAngle + axis.x * axis.x * oneMinusCosAngle,
        axis.x * axis.y * oneMinusCosAngle - axis.z * sinAngle,
        axis.x * axis.z * oneMinusCosAngle + axis.y * sinAngle,

        axis.y * axis.x * oneMinusCosAngle + axis.z * sinAngle,
        cosAngle + axis.y * axis.y * oneMinusCosAngle,
        axis.y * axis.z * oneMinusCosAngle - axis.x * sinAngle,

        axis.z * axis.x * oneMinusCosAngle - axis.y * sinAngle,
        axis.z * axis.y * oneMinusCosAngle + axis.x * sinAngle,
        cosAngle + axis.z * axis.z * oneMinusCosAngle
    );

    return rotationMatrix * v;
}


void main() {
    vec3 scaledPosition = vec3(position.x, position.y * u_y_scale + sin(gl_InstanceID % 3000) * 5 * position.y * 0.1f, position.z);
    vec3 rotatedVector = rotateVec3(scaledPosition, vec3(0, 1, 0), u_rotations[gl_InstanceID % 10]);
    vec3 windOffset = u_wind_direction * (position.y * 0.2f) * (sin(u_time + 1) * 1.0f);

    gl_Position = u_MVP * vec4(rotatedVector + offset + chunkOffset + windOffset, 1.0f);
	v_position = position;
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec3 v_position;

void main() {
    color = vec4(vec3(0.0f, 0.7f, 0.3f) * (v_position.y * 0.2f), 1.0f - (v_position.y * 0.05f));
};
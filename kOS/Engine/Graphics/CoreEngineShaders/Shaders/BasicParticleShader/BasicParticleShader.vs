R"(
#version 460 core

layout(location = 0) in vec3 inPos;       // base quad vertex
layout(location = 2) in vec3 instancePos; // per-particle
layout(location = 3) in vec2 instanceScale;
layout(location = 4) in vec4 instanceColor;
layout(location = 5) in float instanceRot;

out vec4 vColor;

uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Rotation around Z axis
    mat2 rot = mat2(cos(instanceRot), -sin(instanceRot),
                    sin(instanceRot),  cos(instanceRot));

    // Apply rotation and scaling (2D)
    vec2 scaled = inPos.xy * instanceScale;
    vec2 rotated = rot * scaled;

    vec3 worldPos = instancePos + vec3(rotated, inPos.z);

    gl_Position = projection * view * vec4(worldPos, 1.0);
    vColor = instanceColor;
}
)"
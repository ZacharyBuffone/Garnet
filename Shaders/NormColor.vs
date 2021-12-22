#version 410 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 norm;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec3 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 vertexNorm; // specify a color output to the fragment shader

void main() {
    gl_Position = projection * view * model * vec4(pos, 1.0);
    vertexNorm = norm;
}

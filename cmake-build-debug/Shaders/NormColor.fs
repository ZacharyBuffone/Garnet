#version 410 core
out vec4 FragColor;

in vec3 vertexNorm; // the input variable from the vertex shader (same name and same type)

void main() {
    FragColor = vec4(vertexNorm, 1.0);
}
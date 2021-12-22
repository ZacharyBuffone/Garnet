#version 410 core
in vec2 uvCoords; // the input variable from the vertex shader (same name and same type)

out vec4 FragColor;

uniform sampler2D MainTexture;

void main() {
    FragColor = texture(MainTexture, uvCoords);
}
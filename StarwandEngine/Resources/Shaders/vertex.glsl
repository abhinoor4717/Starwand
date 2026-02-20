#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in float aUseTexture;

out vec3 vertexColor;
out vec2 uvCoords;
out float useTexture;

void main() {
	gl_Position = vec4(aPos, 1.0);
	vertexColor = aColor;
	uvCoords = aTexCoords;
	useTexture = aUseTexture;
}
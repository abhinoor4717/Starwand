#version 330 core

in vec3 vertexColor;
in vec2 uvCoords;
in float useTexture;
out vec4 FragColor;

uniform sampler2D sampler;

void main() {
	if (useTexture == 1.0) {
		FragColor = texture(sampler, uvCoords);
	} else {
		FragColor = vec4(vertexColor, 1.0);
	}
}
#include "Platform/OpenGL/OpenGLTexture2D.h"

#include <glad/glad.h>

#include "stb_image.h"
#include "Core/Log.h"
#include "Core/Exceptions.h"

namespace Starwand {
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path) {
		int width, height, channels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* imageData = stbi_load(path.c_str(), &width, &height, &channels, 4);
		if (!imageData) {
			const char* msg = stbi_failure_reason();
			SWE_ERROR("Unable to load texture '{}': {}", path, msg);
			throw TextureLoadingException(msg);
		}

		glGenTextures(1, &m_RendererId);
		Bind();

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
		glGenerateMipmap(GL_TEXTURE_2D);

		SWE_TRACE("Loaded texture '{}' of size ({}, {}) with {} channels!", path, width, height, channels);

		stbi_image_free(imageData);
	}

	OpenGLTexture2D::~OpenGLTexture2D() {
		glDeleteTextures(1, &m_RendererId);
	}

	void OpenGLTexture2D::Bind() const {
		glBindTexture(GL_TEXTURE_2D, m_RendererId);
	}

	void OpenGLTexture2D::Unbind() const {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
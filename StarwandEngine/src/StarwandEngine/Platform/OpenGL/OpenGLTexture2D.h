#pragma once

#include "Graphics/Texture2D.h"

namespace Starwand {
	class OpenGLTexture2D : public Texture2D {
	public:
		OpenGLTexture2D(const std::string& path);
		~OpenGLTexture2D();

		void Bind() const override;
		void Unbind() const override;

	private:
		uint32_t m_RendererId;
	};
}
#include "Graphics/Texture2D.h"

#include "Graphics/GraphicsAPI.h"
#include "Core/Log.h"

#include "Platform/OpenGL/OpenGLTexture2D.h"

namespace Starwand {
	std::shared_ptr<Texture2D> Texture2D::Create(const std::string& path) {
		switch (GraphicsAPI::GetAPI()) {
			case GraphicsAPI::API::OpenGL:		return std::make_shared<OpenGLTexture2D>(path);
			case GraphicsAPI::API::None:		{ SWE_FATAL("Graphics API not found!"); exit(-1); }
		}

		return nullptr;
	}
}
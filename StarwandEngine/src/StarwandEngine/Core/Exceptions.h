#pragma once

#include <stdexcept>

namespace Starwand {

	class ShaderException : public std::runtime_error {
	public:
		explicit ShaderException(const std::string& message) : std::runtime_error(message) {}
	};

	class InvalidVertexShaderException : public ShaderException {
	public:
		explicit InvalidVertexShaderException(const std::string& message) : ShaderException(message) {}
	};

	class InvalidFragmentShaderException : public ShaderException {
	public:
		explicit InvalidFragmentShaderException(const std::string& message) : ShaderException(message) {}
	};

	class ShaderLinkException : public ShaderException {
	public:
		explicit ShaderLinkException(const std::string& message) : ShaderException(message) {}
	};

	class InvalidShaderUniformException : public ShaderException {
	public:
		explicit InvalidShaderUniformException(const std::string& message) : ShaderException(message) {}
	};

	class TextureException : public std::runtime_error {
	public:
		explicit TextureException(const std::string& message) : std::runtime_error(message) {}
	};

	class TextureLoadingException : public TextureException {
	public:
		explicit TextureLoadingException(const std::string& message) : TextureException(message) {}
	};
}

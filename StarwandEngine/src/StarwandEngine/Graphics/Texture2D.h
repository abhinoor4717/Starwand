#pragma once

#include "Core/Core.h"

#include <memory>
#include <string>

namespace Starwand {
	class SW_API Texture2D {
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static std::shared_ptr<Texture2D> Create(const std::string& path);
	};
}
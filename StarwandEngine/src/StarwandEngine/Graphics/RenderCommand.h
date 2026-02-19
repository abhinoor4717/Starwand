#pragma once

#include "Graphics/VertexArray.h"

namespace Starwand {
	class RenderCommand {
	public:
		static void SetClearColor(float r, float g, float b, float a);
		static void Clear();
		static void DrawIndexed(std::shared_ptr<VertexArray> vertexArray);
		static void SetViewport(int x, int y, int w, int h);
	};
}
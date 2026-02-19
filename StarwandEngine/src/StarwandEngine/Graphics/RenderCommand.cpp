#include "Graphics/RenderCommand.h"

#include "Graphics/GraphicsAPI.h"
#include <glad/glad.h>
#include "Core/Log.h"

namespace Starwand {
	void RenderCommand::SetClearColor(float r, float g, float b, float a) {
		switch (GraphicsAPI::GetAPI()) {
			case GraphicsAPI::API::OpenGL:			glClearColor(r, g, b, a);
			case GraphicsAPI::API::None:			{ SWE_FATAL("Graphics API not found!"); exit(-1); }
		}
	}

	void RenderCommand::Clear() {
		switch (GraphicsAPI::GetAPI()) {
			case GraphicsAPI::API::OpenGL:			glClear(GL_COLOR_BUFFER_BIT);
			case GraphicsAPI::API::None:			{ SWE_FATAL("Graphics API not found!"); exit(-1); }
		}
	}

	void RenderCommand::DrawIndexed(std::shared_ptr<VertexArray> vertexArray) {
		switch (GraphicsAPI::GetAPI()) {
			case GraphicsAPI::API::OpenGL: {
				vertexArray->Bind();
				glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
			}
			case GraphicsAPI::API::None: { SWE_FATAL("Graphics API not found!"); exit(-1); }
		}
	}

	void RenderCommand::SetViewport(int x, int y, int w, int h) {
		switch (GraphicsAPI::GetAPI()) {
			case GraphicsAPI::API::OpenGL:			glViewport(x, y, w, h);
			case GraphicsAPI::API::None:			{ SWE_FATAL("Graphics API not found!"); exit(-1); }
		}
	}
}
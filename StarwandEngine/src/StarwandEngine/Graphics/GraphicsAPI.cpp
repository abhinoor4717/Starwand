#include "Graphics/GraphicsAPI.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Core/Log.h"

namespace Starwand {

    GraphicsAPI::API GraphicsAPI::s_API = GraphicsAPI::API::OpenGL;

    void GraphicsAPI::Initalize() {
        switch (s_API) {
            case API::OpenGL: {
                if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                    SWE_FATAL("GLAD failed to initalize!");
                    glfwTerminate();
                    exit(-1);
                }
                break;
            }
            case API::None: {
                SWE_FATAL("Graphics API not found!");
                exit(-1);
            }
        }
    }

}

#include "Test.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Graphics/VertexArray.h"
#include "Log.h"
namespace Starwand {
    void init() {
        Log::Init();
    }

    void greet() {
        std::cout << "Greetings from StarwandEngine" << std::endl;
    }

    const char* vertexSrc = R"(
    #version 330 core
    layout(location = 0) in vec3 a_Position;

    void main()
    {
        gl_Position = vec4(a_Position, 1.0);
    }
    )";

    const char* fragmentSrc = R"(
    #version 330 core
    out vec4 FragColor;

    void main()
    {
        FragColor = vec4(1.0, 0.2, 0.2, 1.0);
    }
    )";

    static GLuint CompileShader(GLenum type, const char* src)
    {
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &src, nullptr);
        glCompileShader(shader);

        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char log[1024];
            glGetShaderInfoLog(shader, 1024, nullptr, log);
            std::cout << "Shader compile error:\n" << log << std::endl;
        }

        return shader;
    }

    static GLuint CreateShaderProgram()
    {
        GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexSrc);
        GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);

        GLuint program = glCreateProgram();
        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);

        GLint success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success)
        {
            char log[1024];
            glGetProgramInfoLog(program, 1024, nullptr, log);
            std::cout << "Shader link error:\n" << log << std::endl;
        }

        glDeleteShader(vs);
        glDeleteShader(fs);

        return program;
    }

    void test() {
        SWE_INFO("Hello from Starwand!");

        if (!glfwInit())
        {
            std::cout << "Failed to init GLFW\n";
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle Test", nullptr, nullptr);
        if (!window)
        {
            std::cout << "Failed to create window\n";
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to init GLAD\n";
            return;
        }

        // ================= GEOMETRY =================

        float vertices[] = {
            -0.5f, -1.0f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };

        unsigned int indices[] = {
            0, 1, 2
        };

        auto va = VertexArray::Create();
        auto vb = VertexBuffer::Create(vertices, sizeof(vertices), BufferUsage::Static);
        vb->SetLayout(BufferLayout(
            {
                BufferElement(ShaderDataType::Float3, "position", false)
            }
        ));
        auto ib = IndexBuffer::Create(indices, sizeof(indices));
        va->AddVertexBuffer(vb);
        va->SetIndexBuffer(ib);

        GLuint shader = CreateShaderProgram();

        // ================= LOOP =================

        while (!glfwWindowShouldClose(window))
        {
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shader);
            va->Bind();
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }
}
#include "Test.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace StarwandEngine {
    void greet() {
        std::cout << "Greetings from StarwandEngine" << std::endl;
    }

    void test() {
        if (!glfwInit()) {
            std::cout << "GLFW failed to initialize!\n";
            return;
        }

        GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
        if (!window) {
            std::cout << "Failed to create window!\n";
            return;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to load glad\n";
            return;
        }

        float vertices[] = {
            // Vertex position      // Color
            -0.5f, -0.5f, 1.0f,     
            0.5f, -0.5f, 1.0f,      
            0.5f, 0.5f, 1.0f,       

            // -0.5f, -0.5f, 1.0f,     1.0f, 0.0f, 0.0f,
            // -0.5f, 0.5f, 1.0f,      1.0f, 1.0f, 0.0f,
            // 0.5f, 0.5f, 1.0f,       1.0f, 1.0f, 0.0f,
        };

        unsigned short indices[] = {
                0, 1, 2
        };

        GLuint vb, ib, vl;

        glGenBuffers(1, &vb);
        glBindBuffer(GL_ARRAY_BUFFER, vb);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &ib);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
        glEnableVertexAttribArray(0);

        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
            glBindBuffer(GL_ARRAY_BUFFER, vb);
            glDrawRangeElements(GL_TRIANGLES, 0, 3, 3, GL_UNSIGNED_SHORT, NULL);

            glfwPollEvents();
            glfwSwapBuffers(window);

        }

        glfwTerminate();
    }
}
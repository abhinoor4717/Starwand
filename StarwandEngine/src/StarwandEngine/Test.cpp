#include "Test.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
            glfwSwapBuffers(window);

        }

        glfwTerminate();
    }
}
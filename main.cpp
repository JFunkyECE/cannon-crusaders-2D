#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    glfwTerminate();

    GLuint version = glewInit();
    if (version != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(version) << '\n';
        return -1;
    }

    std::cout << "Successfully initialized GLFW and GLEW!\n";
    return 0;
}

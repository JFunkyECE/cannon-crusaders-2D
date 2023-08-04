#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tank.hpp"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Cannon Crusaders", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    tank::Tank tank(0.5f, 0.0f, 0.1f, 0.1f); //initialize tank


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.0f, 0.5f, 0.0f, 1.0f); // Set clear color to green
        glClear(GL_COLOR_BUFFER_BIT);
        
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            tank.move(-0.01f);
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            tank.move(0.01f);
        }
        tank.render();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
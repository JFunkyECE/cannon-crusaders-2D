#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.hpp"
#include <iostream>

int main(void){

    // Create Game object
    Game game;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(game.getWindow()))
    {
        game.Update();
        game.Render();
        /* Swap front and back buffers */
        glfwSwapBuffers(game.getWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }
    return 0;
}

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.hpp"
#include <iostream>

int main(void){
    // Create Game object
    Game game;

    //Application Loop
    while (!glfwWindowShouldClose(game.getWindow()))
    {
        game.Update();
        game.Render();
        glfwSwapBuffers(game.getWindow());
        glfwPollEvents();
    }
    return 0;
}
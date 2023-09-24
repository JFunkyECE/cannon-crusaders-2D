#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.hpp"
#include <iostream>
#include <chrono>

int main(void){

    // Create Game object
    Game game;

    auto lastTime = std::chrono::high_resolution_clock::now();
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(game.getWindow()))
    {
        
        auto now = std::chrono::high_resolution_clock::now();
        if(std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime).count() >= 16){
            game.Update();
            lastTime = now;
        }
        game.Render();
        /* Swap front and back buffers */
        glfwSwapBuffers(game.getWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }
    return 0;
}

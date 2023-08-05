#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tank.hpp"
#include <iostream>


void Keyboard_Input(GLFWwindow* window, tank::Tank& tank, float& lastshot_time){
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            tank.move(-0.01f);  // Move the tank to the left
        }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            tank.move(0.01f);  // Move the tank to the right
        }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            float current_time = glfwGetTime(); //gives time in seconds
            if(current_time - lastshot_time >= 0.2f){ //limit shooting to one per 0.2 seconds or 5 shots per second
                tank.shoot();
                lastshot_time = current_time;
            }
        }

    // add input for pausing game
    
}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(600, 800, "Cannon Crusaders", NULL, NULL);
    if (!window)
    {
        glfwTerminate(); //need this hear because after initialization
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Create a tank
    tank::Tank myTank;
    //initialize shot timer.
    float lastshot_time = 0.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.5f, 0.0f, 1.0f); // Set clear color to green
       
        Keyboard_Input(window, myTank, lastshot_time);

        myTank.updateCannonballs();
        // Render the tank
        myTank.render();
        myTank.renderCannonballs();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
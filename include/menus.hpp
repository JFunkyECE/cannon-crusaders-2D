#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>



namespace menu{

class Menu{
public:
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu(): x_(-1.0f), y_(1.0f){
        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);
        glGenBuffers(1, &VBO_);
    }

    ~Menu(){
        glDeleteBuffers(1, &VBO_);
        glDeleteVertexArrays(1, &VAO_);
    }

//start menu
    void renderStartMenu(){

        //create vertice for CANNON
        float Cannon_Vertices[] = {
                x_, y_,
                x_ + 0.1f, y_,
                x_ + 0.1f, y_ - 0.025f,
                x_, y_ - 0.025f,

                x_, y_,
                x_ + 0.025f, y_,
                x_ + 0.025f, y_ - 0.1f,
                x_ , y_ - 0.1f,

                x_ , y_ - 0.075f,
                x_ + 0.1f, y_ - 0.075f,
                x_ + 0.1f, y_ - 0.1f,   
                x_, y_ - 0.1f              
        };
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Cannon_Vertices), Cannon_Vertices, GL_STATIC_DRAW);

        // Define how to interpret the vertex data
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Draw the "C"
        glBindVertexArray(VAO_);
        glDrawArrays(GL_QUADS, 0, 16);

        // Optionally, unbind the VBO and VAO
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        //create vertice for CRUSADERS


        //create vertice for START: ENTER

        //CONTROLS
        //MOVE:  ARROWS
        //PAUSE: P
        //SHOOT: SPACE
    }
//contains the following text
//      Cannon Crusaders
//
//      Start: Press ENTER
//      Quit: Press Q
//      How to Play
//      -> move right
//      <- move left
//      SPACE shoot


//ingame
    void renderInGame();
//enemies left counter thats it

//Pause menu
    void renderPause();
//Small square goes over screen with following text
//Paused
//Press ENTER to continue
//Press R to Restart
//Press M to go back to the menu
//Press Q to quit application


//ENDGAME
    void renderEndGame();
//depending on win or lose
//Great Job or Almost there
//press R to restart
//press M to go back to menu
//press Q to quit application

//render text function 

private:
GLuint VAO_, VBO_;
float x_,y_;
};

}
#endif
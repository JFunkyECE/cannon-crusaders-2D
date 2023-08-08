#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.hpp"


namespace menu{

class Menu{
public:
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu(): x_(-1.0f), y_(1.0f), laststate(0){  
        float Vertices[] = {
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
        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);

        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }

    ~Menu(){
        glDeleteBuffers(1, &VBO_);
        glDeleteVertexArrays(1, &VAO_);
    }

    void updateMenu(){
        //this is where depending on the currentstate we will alter vertices
        // if(last_state == current){
        //     return;
        // }else{
        //     //add other changes to vertices here
        // }


        // //update laststate to currentstate 
        // last_state = current;
    }


//start menu
    void renderMenu(int p){
        if (p == 0){
        glBindVertexArray(VAO_);
        glColor3f(1.0f,1.0f,1.0f);
        for(int i = 0; i < 3; ++i){
        glDrawArrays(GL_QUADS,i*4,4);
        }
        }
    }
//contains the following text
//      Cannon Crusaders
//
//      Start: Press ENTER
//      Quit: Press Q
//      Controls
//      -> move right
//      <- move left
//      SPACE shoot

    void renderStart();
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
int laststate;
};

}
#endif
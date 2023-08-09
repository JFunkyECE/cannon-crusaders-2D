#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.hpp"
#include <iostream>

namespace menu{

class Menu{
public:
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu(): x_(-1.0f), y_(1.0f), currentstate_(0){  
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

    void updateMenu(int i){
        currentstate_ = i;
        //called to alter vertices depending on currentstate_
    }

    void renderMenu(){
        if (currentstate_ = 0){ //means we on start menu
        std::cout << "Rendering Menu" << std::endl;
        glBindVertexArray(VAO_);
        glColor3f(1.0f,1.0f,1.0f);
        for(int i = 0; i < 3; ++i){
        glDrawArrays(GL_QUADS,i*4,4);
        }
        }
    }


private:
GLuint VAO_, VBO_;
float x_,y_;
int currentstate_;
};

}
#endif
#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.hpp"
#include <iostream>
#include <vector>

namespace menu{

class Menu{
public:
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu() : x_(-1.0f), y_(1.0f), currentstate_(0){  
        vertices_.reserve(1000); //will never reach end

        AddToVec('C', x_, y_);

        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);

        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices_.size(), vertices_.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    ~Menu(){
        glDeleteBuffers(1, &VBO_);
        glDeleteVertexArrays(1, &VAO_);
    }

    void updateMenu(int i, int enemies_defeated = 0){
        currentstate_ = i;
        //called to alter vertices depending on currentstate_

        
    }

    void renderMenu(){
          
        glBindVertexArray(VAO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glColor3f(1.0f,1.0f,1.0f);
        int number_quads = vertices_.size() / 8; //each quad has 4 2 point coords
        for(int i = 0; i < number_quads; ++i){
        glDrawArrays(GL_QUADS,i*4,4);
        }
    }   
    //adds char to vector
    void AddToVec(char letter, float x, float y){
        switch(letter){
            case 'C':

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);
                break;
        }
    }


private:
GLuint VAO_, VBO_;
float x_,y_;
int currentstate_;
std::vector<float> vertices_;
};

}
#endif
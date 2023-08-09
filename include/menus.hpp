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

    Menu() : x_(-1.0f), y_(1.0f), currentstate_(0), score(0){  
        vertices_.reserve(1000); //will never reach end

        AddCharToVec('C', x_, y_);
        AddCharToVec('A', x_ + .11f, y_);
        AddCharToVec('N', x_ + .22f, y_);
        AddCharToVec('N', x_ + .33f, y_);
        AddCharToVec('O', x_ + .44f, y_);
        AddCharToVec('N', x_ + .55f, y_);
        AddCharToVec('C', x_ + .77f, y_);
        AddCharToVec('R', x_ + .88f, y_);
        AddCharToVec('U', x_ + .99f, y_);
        AddCharToVec('S', x_ + 1.1f, y_);
        AddCharToVec('A', x_ + 1.21f, y_);
        AddCharToVec('D', x_ + 1.32f, y_);
        AddCharToVec('E', x_ + 1.43f, y_);
        AddCharToVec('R', x_ + 1.54f, y_);
        AddCharToVec('S', x_ + 1.65f, y_);
        
        AddCharToVec('S', x_ , y_ - 0.3f);
        AddCharToVec('T', x_ + .11f, y_ - 0.3f);
        AddCharToVec('A', x_ + .22f, y_ - 0.3f);
        AddCharToVec('R', x_ + .33f, y_ - 0.3f);
        AddCharToVec('T', x_ + .44f, y_ - 0.3f);
        AddCharToVec('-', x_ + .55f, y_ - 0.3f);
        AddCharToVec('E', x_ + .66f, y_ - 0.3f);
        AddCharToVec('N', x_ + .77f, y_ - 0.3f);
        AddCharToVec('T', x_ + .88f, y_ - 0.3f);
        AddCharToVec('E', x_ + .99f, y_ - 0.3f);
        AddCharToVec('R', x_ + 1.1f, y_ - 0.3f);
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
        //make check so if nothing changes state wise can just go straight to render without reallocating

        //this will, depending on i, clear the vector 
        
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
    //implement after
    void AddIntToVec(int number, float x, float y){}
    //adds char to vector
    void AddCharToVec(char letter, float x, float y){
        switch(letter){
            case 'A':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side of A

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top of A

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side of A

                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle of A
                break;
            case 'C':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom
                break;

            case 'D': //not done
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side
                break;
            case 'E': //not done
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side of A

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top of A

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle
                break;
            case 'G': //not done
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side of A

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top of A

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side of A
                break;
            case 'H':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side of H

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side of H

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle of H
                break;
            case 'I':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x + 0.0375f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f); //middle

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom
                break;
            case 'L':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom
                break;
            case 'M': //not done
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side of H

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0625f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.05f); //left side diag

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.0625f); vertices_.push_back(y - 0.05f); //right side diag

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side of H
                break;
            case 'N':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f); //middle
                break;
            case 'O':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side
                break;    
            case 'P':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f); //right side

                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle
                break;
            case 'Q':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f); //right side
                break;
            case 'R': //not done
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f); //right side

                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right

                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle
                break;
            case 'S': //not done
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side
                break;
            case 'T':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x + 0.0375f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f); //middle
                break;
            case 'U':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right side
                break;
            case 'Y': 
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x); vertices_.push_back(y - 0.05f); //left

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f); //right side

                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f); //middle vertical

                vertices_.push_back(x); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x); vertices_.push_back(y - 0.05f); //middle horizontal
                break;
            case '-':
                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle of A
                break;
        }
    }


private:
GLuint VAO_, VBO_;
float x_,y_;
int currentstate_;
int score;
std::vector<float> vertices_;
};

}
#endif
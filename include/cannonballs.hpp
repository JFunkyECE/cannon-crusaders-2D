#ifndef cannonballs_hpp
#define cannonballs_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Cannonballs {

public:
    //constructor that makes cannonball at current location of cannon
    Cannonballs(float x, float y): x_(x + 0.02f), y_(y + .1f), exists_(true){
        //x_ and y_ now represent the bottom left corner of the cannonball
        //using squares initially for simplicity, will update to circles if time permitted
        float cannonball_vertices[] = {
            x_ , y_ , //bottom left
            x_ , y_ + 0.04f, //top left
            x_ + .04f, y_ + 0.04f, //top right
            x_ + 0.04f, y_ //bottom right

        };
        //initialize VAO and VBO for cannonball object
        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);

        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);

        glBufferData(GL_ARRAY_BUFFER, sizeof(cannonball_vertices), cannonball_vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }


    

private:
float x_,y_; //stores key data related to position of ball
bool exists_; //stores whether bullet has made contact with enemy or is out of window
GLunit VAO_ VBO_; //for each bullet
};


#endif
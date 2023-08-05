#ifndef enemy_hpp
#define enemy_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>
namespace Ducks{

//create enemy class that holds a vector of enemies with information about current position 

class Enemy{

public:

    //need constructor that reserves based on difficulty, ie either 20 or 50 enemies.
    Enemy(): y_(1.0f), is_active(true){
        static std::random_device rd;  // Will be used to obtain a seed for the random number engine
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<> dis(-1.0, 0.85);
        x_ = dis(gen); //gives x random number between -1.0 and 0.85

        //initialize enemy with given starting position
        //set vertices based on position
        //vertices for body 1
        //vertices for body 2
        //vertices for body 3
        //vertices for beak
        //vertices for eye

        //initially enemy will be .15 by .15 square just to verify that implementation of spawning works.
        float duckbody_vertices[] = {
            x_ , y_ - .15f , //bottom left
            x_ , y_ , //top left
            x_ + .15f, y_ , //top right
            x_ + 0.15f, y_ - .15f //bottom right

        };
        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);

        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);

        glBufferData(GL_ARRAY_BUFFER, sizeof(duckbody_vertices), duckbody_vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }
    //destructor
    ~Enemy(){
        glDeleteBuffers(1, &VBO_);
        glDeleteVertexArrays(1, &VAO_);
    }

    //where the movement algorithm will be implemented
    //straight line down for now, will implement more complex movement once collision and other game aspects made.
    void move( float dy, float dx){
        y_ += dy;
        
        // Update the vertices of the ducky
        float vertices[] = {
            x_ , y_ - .15f , //bottom left
            x_ , y_ , //top left
            x_ + .15f, y_ , //top right
            x_ + 0.15f, y_ - .15f //bottom right
        };
        glBindVertexArray(VAO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    }

    void render(){
        glColor3f(1.0f,1.0f,0.0f);
        glBindVertexArray(VAO_);
        glDrawArrays(GL_QUADS,0,4);
    }

    float getX() const{ return x_;}
    float getY() const{ return y_;}
    bool isActive() const{return is_active;}
    void setActive(bool setting){is_active = setting;}

    //bool check_collision();

private:
bool is_active;
float x_,y_;
GLuint VAO_, VBO_;
};



}
#endif
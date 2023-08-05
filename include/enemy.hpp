#ifndef enemy_hpp
#define enemy_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Ducks{

//create enemy class that holds a vector of enemies with information about current position 

class Enemy{

public:

    //need constructor that reserves based on difficulty, ie either 20 or 50 enemies.
    Enemy(float Xi, float Yi){
        //initialize enemy with given starting position
        //set vertices based on position

    }
    //destructor
    ~Enemy() = default;

    //where the movement algorithm will be implemented
    void move();

    float getX();
    float getY();

    //bool check_collision();

private:
float x_,y_;
GLuint VAO_, VBO_;
};



}
#endif
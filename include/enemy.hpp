#ifndef enemy_hpp
#define enemy_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>
namespace Ducks{

//create enemy class that holds a vector of enemies with information about current position 

class Enemy{

public:

    Enemy();
    ~Enemy();
    void move( float dy);
    void render();
    float getX() const;
    float getY() const;
    bool isActive() const;
    void setActive(bool setting);
    
private:
bool is_active;
float x_,y_;
GLuint VAO_, VBO_;
};



}
#endif
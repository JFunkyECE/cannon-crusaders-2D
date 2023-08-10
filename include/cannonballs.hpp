#ifndef cannonballs_hpp
#define cannonballs_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Cannonballs {

public:

    
    Cannonballs(float x, float y);
    ~Cannonballs();

    void move(float dy);
    void render() const;
    bool exists() const;
    void setExists(bool exists);
    float getX() const;
    float getY() const;

private:
float x_,y_; //stores position of cannnonball
bool exists_; //stores whether cannonball has made contact with enemy or is out of visible window
GLuint VAO_, VBO_; 
};


#endif
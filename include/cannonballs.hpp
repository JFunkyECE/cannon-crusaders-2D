#ifndef cannonballs_hpp
#define cannonballs_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Cannonballs {

public:
    //constructor that makes cannonball at current location of cannon
    Cannonballs(float x, float y);
    //simple destructor to handle VBO and VAO destruction
    ~Cannonballs();
    //handles updating the vertices and VAO and VBO
    void move(float dy);
    void render() const;
    bool exists() const;
    void setExists(bool exists);
    float getX() const;
    float getY() const;
private:
float x_,y_; //stores key data related to position of ball
bool exists_; //stores whether bullet has made contact with enemy or is out of window
GLuint VAO_, VBO_; //for each bullet
};


#endif
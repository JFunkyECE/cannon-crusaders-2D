#ifndef tank_hpp
#define tank_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "cannonballs.hpp"
#include <vector>
#include <iostream>

namespace tank{

class Tank{
public:

    Tank();
    ~Tank();
    void render() const;
    void move(float dx);
    void update_vertices();
    float getX();
    float getY();
    float getX() const;
    float getY() const;
    void shoot();
    void updateCannonballs();
    void renderCannonballs() const;
    int live_cannonballs() const;
    std::vector<Cannonballs>& Cannonballpositions();


private:
    float x0,y0,x1,y1; //for position of tank and cannon
    float width_, height_; //for sizing tank
    GLuint tankVAO, launcherVAO, tankVBO, launcherVBO; //VAO and VBO for tank and launcher
    std::vector<Cannonballs> cannonballs_; //stores cannonball data
    int cannonballs_fired; //records # of shots fired
};
}//end of namespace
#endif
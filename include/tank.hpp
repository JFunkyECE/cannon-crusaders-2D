#ifndef tank_hpp
#define tank_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace tank{

class Tank{
public:
    Tank(float x, float y, float width, float height);

    void render() const;

    void move(float dx);

    void handleIP(GLFWwindow* window);

private:
    float x,y; //for position of tank
    float width, height; //for sizing tank

};
}//end of namespace
#endif
#ifndef tank_hpp
#define tank_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace tank{

class Tank{
public:
    Tank(float x, float y, float width, float height): x_(x), y_(y), width_(width), height_(height) {}

    void render() const{
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();    }

    void move(float dx){
        x += dx;
        if(x<0){
            x = 0;
        }else if(x > 1-width){
            x = 1 - width;
        }
    }

    void handleIP(GLFWwindow* window){
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            move(-0.01f);
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            move(0.01f);
        }
    }

private:
    float x_,y_; //for position of tank
    float width_, height_; //for sizing tank

};
}//end of namespace
#endif
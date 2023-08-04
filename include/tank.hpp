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
        glVertex2f(x_, y_);
        glVertex2f(x_ + width_, y_);
        glVertex2f(x_ + width_, y_ + height_);
        glVertex2f(x_, y_ + height_);
        glEnd();    }

    void move(float dx){
        x_ += dx;
        if(x_<0){
            x_ = 0;
        }else if(x_ > 1-width_){
            x_ = 1 - width_;
        }
    }

    void handleIP(GLFWwindow* window){
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            move(-0.05f);
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            move(0.05f);
        }
    }

private:
    float x_,y_; //for position of tank
    float width_, height_; //for sizing tank

};
}//end of namespace
#endif
#ifndef tank_hpp
#define tank_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace tank{

class Tank{
public:
    Tank(float x, float y, float width, float height): x_(x), y_(y), width_(width), height_(height) {
        float tankVertices[] = {
            // Positions
            x - width / 2, y - height / 2,  // Bottom left corner
            x - width / 2, y + height / 2,  // Top left corner
            x + width / 2, y + height / 2,  // Top right corner
            x + width / 2, y - height / 2   // Bottom right corner
        };

        // Initialize the vertices of the cannon launcher
        float launcherVertices[] = {
            // Positions
            x - width / 4, y + height / 2,  // Bottom left corner
            x - width / 4, y + height / 2 + height / 4,  // Top left corner
            x + width / 4, y + height / 2 + height / 4,  // Top right corner
            x + width / 4, y + height / 2   // Bottom right corner
        };

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);


    }

    void render() const{
        
        }

    void move(float dx){
        x_ += dx;
        if(x_< 0.0){
            x_ = 0;
        }else if(x_ > 1.0 -width_){
            x_ = 1.0 - width_;
        }
    }


private:
    float x_,y_; //for position of tank
    float width_, height_; //for sizing tank
    GLuint VAO, tankVBO, launcherVBO;
};
}//end of namespace
#endif
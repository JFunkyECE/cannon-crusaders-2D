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

        // Generate and bind the Vertex Buffer Object (VBO) for the tank
        glGenBuffers(1, &tankVBO);
        glBindBuffer(GL_ARRAY_BUFFER, tankVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(tankVertices), tankVertices, GL_STATIC_DRAW);

        // Generate and bind the Vertex Buffer Object (VBO) for the cannon launcher
        glGenBuffers(1, &launcherVBO);
        glBindBuffer(GL_ARRAY_BUFFER, launcherVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(launcherVertices), launcherVertices, GL_STATIC_DRAW);

        // Specify the layout of the vertex data
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }
     ~Tank() {
        // Clean up
        glDeleteBuffers(1, &tankVBO);
        glDeleteBuffers(1, &launcherVBO);
        glDeleteVertexArrays(1, &VAO);
    }
    void render() const{
        // Bind the VAO and draw the tank and the cannon launcher
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, tankVBO);
        glDrawArrays(GL_QUADS, 0, 4);
        glBindBuffer(GL_ARRAY_BUFFER, launcherVBO);
        glDrawArrays(GL_QUADS, 0, 4);
        }



private:
    float x_,y_; //for position of tank
    float width_, height_; //for sizing tank
    GLuint VAO, tankVBO, launcherVBO;
};
}//end of namespace
#endif
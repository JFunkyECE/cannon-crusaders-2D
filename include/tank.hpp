#ifndef tank_hpp
#define tank_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace tank{

class Tank{
public:
    Tank(){
        //initial positions for tank 
        x0= -0.1f;
        y0= -1.0f;
        x1= -0.04f;
        y1= -0.85f;
        width_ = .2f;
        height_ = .15f;

        float tankVertices[] = {
            // Positions
            x0, y0,  // Bottom left corner
            x0, y0 + height_,  // Top left corner
            x0 + width_ , y0 + height_,  // Top right corner
            x0 + width_  , y0   // Bottom right corner
        };

        // Initialize the vertices of the cannon launcher
        float launcherVertices[] = {
            // Positions
            x1, y1,  // Bottom left corner
            x1, y1 + .1f ,  // Top left corner
            x1 + .08f, y1 + .1f,  // Top right corner
            x1 + .08f, y1   // Bottom right corner
        };

        glGenVertexArrays(1, &tankVAO);
        glBindVertexArray(tankVAO);

        // Generate and bind the Vertex Buffer Object (VBO) for the tank
        glGenBuffers(1, &tankVBO);
        glBindBuffer(GL_ARRAY_BUFFER, tankVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(tankVertices), tankVertices, GL_STATIC_DRAW);

        // Specify the layout of the vertex data
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Generate and bind the Vertex Array Object (VAO) for the launcher
        glGenVertexArrays(1, &launcherVAO);
        glBindVertexArray(launcherVAO);

        // Generate and bind the Vertex Buffer Object (VBO) for the launcher
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

        glColor3f(1.0f,1.0f,1.0f);
        glBindBuffer(GL_ARRAY_BUFFER, tankVBO);
        glDrawArrays(GL_QUADS, 0, 4);

        glColor3f(0.5f,0.5f,0.5f);
        glBindBuffer(GL_ARRAY_BUFFER, launcherVBO);
        glDrawArrays(GL_QUADS, 0, 4);
        }



private:
    float x0,y0,x1,y1; //for position of tank and cannon
    float width_, height_; //for sizing tank
    GLuint VAO, tankVBO, launcherVBO;
};
}//end of namespace
#endif
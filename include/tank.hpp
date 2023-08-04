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
    Tank(): cannonballs_fired(0){
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
        glDeleteVertexArrays(1, &tankVAO);
        glDeleteVertexArrays(1, &launcherVAO);
    }
    void render() const{
        // Bind the VAO and draw the tank and the cannon launcher
        glColor3f(0.5f,0.5f,0.5f);
        glBindVertexArray(tankVAO);
        glBindBuffer(GL_ARRAY_BUFFER, tankVBO);
        glDrawArrays(GL_QUADS, 0, 4);

        glColor3f(0.5f,0.5f,0.5f);
        glBindVertexArray(launcherVAO);
        glBindBuffer(GL_ARRAY_BUFFER, launcherVBO);
        glDrawArrays(GL_QUADS, 0, 4);
        }
    //called when the user presses a or d to move 
    void move(float dx){
        
        if(x0 + dx >= -1.0f && x0 + dx <= 1.0f - width_){
            x0 += dx;
            x1 += dx;
            //now need to update vertices for tank
            update_vertices();
        }
    }
    //updates tank and launcher vertices when move function invoked
    void update_vertices(){

        float tankVertices[] = {
            // Positions
            x0, y0,  // Bottom left corner
            x0, y0 + height_,  // Top left corner
            x0 + width_ , y0 + height_,  // Top right corner
            x0 + width_  , y0   // Bottom right corner
        };

        float launcherVertices[] = {
            // Positions
            x1, y1,  // Bottom left corner
            x1, y1 + .1f ,  // Top left corner
            x1 + .08f, y1 + .1f,  // Top right corner
            x1 + .08f, y1   // Bottom right corner
        };

        glBindVertexArray(tankVAO);
        glBindBuffer(GL_ARRAY_BUFFER, tankVBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(tankVertices), tankVertices);

        glBindVertexArray(launcherVAO);
        glBindBuffer(GL_ARRAY_BUFFER, launcherVBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(launcherVertices), launcherVertices);
    }
    
    float getX(){
        return x0;
    }
    float getY(){
        return y0;
    }

    //adds a cannonball to the vector cannonballs_
    void shoot(){
        int cannonballs_onscreen = 5;
        std::cout<< "Live Cannonballs on screen #"<<live_cannonballs() << std::endl;

        if(live_cannonballs() < cannonballs_onscreen && cannonballs_fired < 200){
                cannonballs_.emplace_back(Cannonballs(x1,y1));
                ++cannonballs_fired;
                std::cout<< "Cannonball #"<<cannonballs_fired<<" fired" << std::endl;
        } else if (cannonballs_fired >= 200){
            //add something here to end the current game.
        }
    }
    void updateCannonballs(){
        for (auto it = cannonballs_.begin(); it != cannonballs_.end(); ++it) {
            if (it->exists()) {
                it->move(0.02f);
                // Check if the cannonball has gone off the top of the screen
                if (it->getY() > 1.0f) {
                    it->setExists(false);
                }
            } 
        }
    }
    void renderCannonballs() const{
        for (const Cannonballs& cannonball : cannonballs_) {
        if (cannonball.exists()) {
            cannonball.render();
        }
        }
    }
    int live_cannonballs() const{
        int count = 0;
        for (const Cannonballs& cannonball : cannonballs_) {
        if (cannonball.exists()) {
            ++count;
        }
        }
        return count; 
    }
private:
    float x0,y0,x1,y1; //for position of tank and cannon
    float width_, height_; //for sizing tank
    GLuint tankVAO, launcherVAO, tankVBO, launcherVBO; //VAO and VBO for tank and launcher
    std::vector<Cannonballs> cannonballs_;
    int cannonballs_fired;
};
}//end of namespace
#endif
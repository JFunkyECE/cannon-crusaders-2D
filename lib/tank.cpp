#include "../include/tank.hpp"

namespace tank{

     Tank::Tank(): cannonballs_fired(0){
        cannonballs_.reserve(200);
        //initial positions for tank 
        x0= -0.1f;
        y0= -1.0f;
        x1= -0.04f;
        y1= -0.85f;
        width_ = .2f;
        height_ = .15f;

        float tankVertices[] = {
            //tank body
            x0, y0,  // Bottom left corner
            x0, y0 + height_,  // Top left corner
            x0 + width_ , y0 + height_,  // Top right corner
            x0 + width_  , y0,   // Bottom right corner
            //cannon
            x1, y1,  // Bottom left corner
            x1, y1 + .1f ,  // Top left corner
            x1 + .08f, y1 + .1f,  // Top right corner
            x1 + .08f, y1   // Bottom right corner
        };

        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);

        // Generate and bind the Vertex Buffer Object (VBO) for the tank
        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(tankVertices), tankVertices, GL_STATIC_DRAW);

        // Specify the layout of the vertex data
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
     Tank::~Tank() {
        // Clean up
        glDeleteBuffers(1, &VBO_);
        glDeleteVertexArrays(1, &VAO_);
    }
    void Tank::render() const{
        // Bind the VAO and draw the tank and the cannon launcher
        glColor3f(0.5f,0.5f,0.5f);
        glBindVertexArray(VAO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glDrawArrays(GL_QUADS, 0, 4);
        glDrawArrays(GL_QUADS, 4, 4);
        }
    //called when the user presses a or d to move 
    void Tank::move(float dx){
        if(x0 + dx > -1.01f && x0 + dx < 1.01f - width_){
            x0 += dx;
            x1 += dx;
            update_vertices();
        }
    }
    //updates tank and launcher vertices when move function invoked
    void Tank::update_vertices(){

        float tankVertices[] = {
            // Positions
            x0, y0,  // Bottom left corner
            x0, y0 + height_,  // Top left corner
            x0 + width_ , y0 + height_,  // Top right corner
            x0 + width_  , y0,   // Bottom right corner
            x1, y1,  // Bottom left corner
            x1, y1 + .1f ,  // Top left corner
            x1 + .08f, y1 + .1f,  // Top right corner
            x1 + .08f, y1   // Bottom right corner
        };

        glBindVertexArray(VAO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(tankVertices), tankVertices);

        
    }
    
    float Tank::getX(){
        return x0;
    }
    float Tank::getY(){
        return y0;
    }
    float Tank::getX() const{
        return x0;
    }
    float Tank::getY() const{
        return y0;
    }
    //adds a cannonball to the vector cannonballs_
    void Tank::shoot(){
        int cannonballs_onscreen = 5;
        //std::cout<< "Live Cannonballs on screen #"<<live_cannonballs() << std::endl;

        if(live_cannonballs() < cannonballs_onscreen && cannonballs_fired < 200){
                
                cannonballs_.emplace_back(x1,y1);
                ++cannonballs_fired;
                std::cout<< "Cannonball #"<<cannonballs_fired<<" fired" << std::endl;
        } else if (cannonballs_fired >= 200){
            cannonballs_.clear();  
            cannonballs_fired = 0;      
            }
    }
    void Tank::updateCannonballs(){
        for (auto it = cannonballs_.begin(); it != cannonballs_.end(); ++it) {
            if (it->exists()) {
                it->move(0.03f);
                // Check if the cannonball has gone off the top of the screen
                if (it->getY() > 1.0f) {
                    it->setExists(false);
                }
            } 
        }
    }
    void Tank::renderCannonballs() const{
        for (const Cannonballs& cannonball : cannonballs_) {
        if (cannonball.exists()) {
            cannonball.render();
        }
        }
    }
    int Tank::live_cannonballs() const{
        int count = 0;
        for (const Cannonballs& cannonball : cannonballs_) {
        if (cannonball.exists()) {
            ++count;
        }
        }
        return count; 
    }
    std::vector<Cannonballs>& Tank::Cannonballpositions(){return cannonballs_;}

     

}
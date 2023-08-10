#include "../include/cannonballs.hpp"

    Cannonballs::Cannonballs(float x, float y): x_(x + 0.02f), y_(y + .1f), exists_(true){
        //x_ and y_ represent the bottom left corner of the cannonball
        float cannonball_vertices[] = {
            x_ , y_ , //bottom left
            x_ , y_ + 0.04f, //top left
            x_ + 0.04f, y_ + 0.04f, //top right
            x_ + 0.04f, y_ //bottom right

        };
        //initialize VAO and VBO for cannonball
        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);

        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);

        glBufferData(GL_ARRAY_BUFFER, sizeof(cannonball_vertices), cannonball_vertices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }
    //simple destructor to handle VBO and VAO destruction
    Cannonballs::~Cannonballs() {
    glDeleteBuffers(1, &VBO_);
    glDeleteVertexArrays(1, &VAO_);
    }    
    //handles moving cannonball by updating the vertices, VAO, and VBO
    void Cannonballs::move(float dy){
        y_ += dy;

        // Update the vertices of the cannonball
        float vertices[] = {
            x_, y_,
            x_, y_ + 0.02f,
            x_ + 0.02f, y_ + 0.02f,
            x_ + 0.02f, y_
        };

        glBindVertexArray(VAO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    }
    //Draws cannonball object
    void Cannonballs::render() const{
        glColor3f(1.0f,1.0f,1.0f);
        glBindVertexArray(VAO_);
        glDrawArrays(GL_QUADS,0,4);
    }

    bool Cannonballs::exists() const {
        return exists_;
    }
    //Sets variable that decides whether cannonball should be rendered
    void Cannonballs::setExists(bool exists) {
        exists_ = exists;
    }
    float Cannonballs::getX() const{
        return x_;
    }
    float Cannonballs::getY() const{ 
        return y_; 
    }
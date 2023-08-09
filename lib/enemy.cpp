#include "../include/enemy.hpp"


namespace Ducks{

    //need constructor that reserves based on difficulty, ie either 20 or 50 enemies.
    Enemy::Enemy(): y_(1.0f), is_active(true){

        static std::random_device rd;  // Will be used to obtain a seed for the random number engine
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<> dis(-1.0, 0.85);
        x_ = dis(gen); //gives x random number between -1.0 and 0.85


        float duck_vertices[] = {
            //body vertices, 3 sections
            x_ + 0.04f, y_ - 0.15f,            //bottom left
            x_ + 0.04f, y_,                    //top left
            x_ + 0.1f, y_ ,                    //top right
            x_ + 0.1f, y_ - 0.15f,             //bottom right
                                
            x_ + 0.04f, y_ - 0.15f,            //bottom left
            x_ + 0.04f, y_ - 0.09f,            //top left
            x_ + 0.15f, y_ - 0.09f,            //top right
            x_ + 0.15f, y_ - 0.15f,            //bottom right

            x_ + 0.12f, y_ - 0.15f,            //bottom left
            x_ + 0.12f, y_ - 0.07f,            //top left
            x_ + 0.15f, y_ - 0.07f,            //top right
            x_ + 0.15f, y_ - 0.15f,            //bottom right
            //eye vertices
            x_ + 0.06f, y_ - 0.06f,            //bottom left
            x_ + 0.06f, y_ - 0.04f,            //top left
            x_ + 0.08f, y_ - 0.04f,            //top right
            x_ + 0.08f, y_ - 0.06f,            //bottom right
            //beak vertices
            x_,y_-0.075f,           //middle
            x_ + 0.04f, y_ - 0.05f, //top right
            x_ + 0.04f, y_ - 0.1f   //bottom right
        };
        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);

        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(duck_vertices), duck_vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    }
    //destructor
    Enemy::~Enemy(){
        glDeleteBuffers(1, &VBO_);
        glDeleteVertexArrays(1, &VAO_);
    }

    //where the movement algorithm will be implemented
    //straight line down for now, will implement more complex movement once collision and other game aspects made.
    void Enemy::move( float dy){
        y_ += dy;
        //x_ += dx; will add if time
        // Update the vertices of the ducky
        float duck_vertices[] = {
            //body vertices, 3 sections
            x_ + 0.04f, y_ - 0.15f,            //bottom left
            x_ + 0.04f, y_,                    //top left
            x_ + 0.1f, y_ ,                    //top right
            x_ + 0.1f, y_ - 0.15f,             //bottom right
                                
            x_ + 0.04f, y_ - 0.15f,            //bottom left
            x_ + 0.04f, y_ - 0.09f,            //top left
            x_ + 0.15f, y_ - 0.09f,            //top right
            x_ + 0.15f, y_ - 0.15f,            //bottom right

            x_ + 0.12f, y_ - 0.15f,            //bottom left
            x_ + 0.12f, y_ - 0.07f,            //top left
            x_ + 0.15f, y_ - 0.07f,            //top right
            x_ + 0.15f, y_ - 0.15f,            //bottom right
            //eye vertices
            x_ + 0.06f, y_ - 0.06f,            //bottom left
            x_ + 0.06f, y_ - 0.04f,            //top left
            x_ + 0.08f, y_ - 0.04f,            //top right
            x_ + 0.08f, y_ - 0.06f,            //bottom right
            //beak vertices
            x_,y_-0.075f,           //middle
            x_ + 0.04f, y_ - 0.05f, //top right
            x_ + 0.04f, y_ - 0.1f   //bottom right
        };
        glBindVertexArray(VAO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(duck_vertices), duck_vertices);

    }

    void Enemy::render(){
        glBindVertexArray(VAO_);
        //draw yellow body of duck
        glColor3f(1.0f,1.0f,0.0f);
        for(int i = 0; i < 3; ++i){
        glDrawArrays(GL_QUADS,i*4,4);
        }
        //draw black eye
        glColor3f(0.0f,0.0f,0.0f);
        glDrawArrays(GL_QUADS, 12, 4);

        //draw orange beak
        glColor3f(1.0f, 0.5f, 0.0f);
        glDrawArrays(GL_TRIANGLES, 16, 3);
    }

    float Enemy::getX() const{ return x_;}
    float Enemy::getY() const{ return y_;}
    bool Enemy::isActive() const{return is_active;}
    void Enemy::setActive(bool setting){is_active = setting;}

}
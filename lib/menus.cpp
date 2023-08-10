#include "../include/menus.hpp"

namespace menu{

    Menu::Menu() : x_(-1.0f), y_(1.0f), currentstate_(0), score(0){  
        vertices_.reserve(1000); //will never reach end

        AddCharToVec('C', x_, y_);
        AddCharToVec('A', x_ + .11f, y_);
        AddCharToVec('N', x_ + .22f, y_);
        AddCharToVec('N', x_ + .33f, y_);
        AddCharToVec('O', x_ + .44f, y_);
        AddCharToVec('N', x_ + .55f, y_);
        AddCharToVec('C', x_ + .77f, y_);
        AddCharToVec('R', x_ + .88f, y_);
        AddCharToVec('U', x_ + .99f, y_);
        AddCharToVec('S', x_ + 1.1f, y_);
        AddCharToVec('A', x_ + 1.21f, y_);
        AddCharToVec('D', x_ + 1.32f, y_);
        AddCharToVec('E', x_ + 1.43f, y_);
        AddCharToVec('R', x_ + 1.54f, y_);
        AddCharToVec('S', x_ + 1.65f, y_);
        
        AddCharToVec('S', x_ , y_ - 0.3f);
        AddCharToVec('T', x_ + .11f, y_ - 0.3f);
        AddCharToVec('A', x_ + .22f, y_ - 0.3f);
        AddCharToVec('R', x_ + .33f, y_ - 0.3f);
        AddCharToVec('T', x_ + .44f, y_ - 0.3f);
        AddCharToVec('-', x_ + .55f, y_ - 0.3f);
        AddCharToVec('P', x_ + .66f, y_ - 0.3f);
        AddCharToVec('R', x_ + .77f, y_ - 0.3f);
        AddCharToVec('E', x_ + .88f, y_ - 0.3f);
        AddCharToVec('S', x_ + .99f, y_ - 0.3f);
        AddCharToVec('S', x_ + 1.1f, y_ - 0.3f);
        AddCharToVec('E', x_ + 1.32f, y_ - 0.3f);
        AddCharToVec('N', x_ + 1.43f, y_ - 0.3f);
        AddCharToVec('T', x_ + 1.54f, y_ - 0.3f);
        AddCharToVec('E', x_ + 1.65f, y_ - 0.3f);
        AddCharToVec('R', x_ + 1.76f, y_ - 0.3f);

        AddCharToVec('Q', x_ , y_ - 0.45f);
        AddCharToVec('U', x_ + .11f, y_ - 0.45f);
        AddCharToVec('I', x_ + .22f, y_ - 0.45f);
        AddCharToVec('T', x_ + .33f, y_ - 0.45f);
        AddCharToVec('-', x_ + .44f, y_ - 0.45f);
        AddCharToVec('E', x_ + .55f, y_ - 0.45f);
        AddCharToVec('S', x_ + .66f, y_ - 0.45f);
        AddCharToVec('C', x_ + .77f, y_ - 0.45f);
        

        AddCharToVec('I', x_ , y_ - 0.7f);
        AddCharToVec('N', x_ + .11f, y_ - 0.7f);
        AddCharToVec('-', x_ + .22f, y_ - 0.7f);
        AddCharToVec('G', x_ + .33f, y_ - 0.7f);
        AddCharToVec('A', x_ + .44f, y_ - 0.7f);
        AddCharToVec('M', x_ + .55f, y_ - 0.7f);
        AddCharToVec('E', x_ + .66f, y_ - 0.7f);
        AddCharToVec('C', x_ + .88f, y_ - 0.7f);
        AddCharToVec('O', x_ + .99f, y_ - 0.7f);
        AddCharToVec('N', x_ + 1.1f, y_ - 0.7f);
        AddCharToVec('T', x_ + 1.21f, y_ - 0.7f);
        AddCharToVec('R', x_ + 1.32f, y_ - 0.7f);
        AddCharToVec('O', x_ + 1.43f, y_ - 0.7f);
        AddCharToVec('L', x_ + 1.54f, y_ - 0.7f);
        AddCharToVec('S', x_ + 1.65f, y_ - 0.7f);
        
        //left arrow - MOVE LEFT
        AddCharToVec('<', x_ , y_ - 0.85f);
        AddCharToVec('-', x_ + .05f, y_ - 0.85f);
        AddCharToVec('M', x_ + .21f, y_ - 0.85f);
        AddCharToVec('O', x_ + .32f, y_ - 0.85f);
        AddCharToVec('V', x_ + .43f, y_ - 0.85f);
        AddCharToVec('E', x_ + .54f, y_ - 0.85f);
        AddCharToVec('L', x_ + .76f, y_ - 0.85f);
        AddCharToVec('E', x_ + .87f, y_ - 0.85f);
        AddCharToVec('F', x_ + .98f, y_ - 0.85f);
        AddCharToVec('T', x_ + 1.09f, y_ - 0.85f);

        //right arrow - MOVE RIGHT
        AddCharToVec('-', x_ , y_ - 1.0f);
        AddCharToVec('>', x_ + .05f, y_ - 1.0f);
        AddCharToVec('M', x_ + .21f, y_ - 1.0f);
        AddCharToVec('O', x_ + .32f, y_ - 1.0f);
        AddCharToVec('V', x_ + .43f, y_ - 1.0f);
        AddCharToVec('E', x_ + .54f, y_ - 1.0f);
        AddCharToVec('R', x_ + .76f, y_ - 1.0f);
        AddCharToVec('I', x_ + .87f, y_ - 1.0f);
        AddCharToVec('G', x_ + .98f, y_ - 1.0f);
        AddCharToVec('H', x_ + 1.09f, y_ - 1.0f);
        AddCharToVec('T', x_ + 1.20f, y_ - 1.0f);

        //SPACE - SHOOT
        AddCharToVec('S', x_ , y_ - 1.15f);
        AddCharToVec('P', x_ + .11f, y_ - 1.15f);
        AddCharToVec('A', x_ + .22f, y_ - 1.15f);
        AddCharToVec('C', x_ + .33f, y_ - 1.15f);
        AddCharToVec('E', x_ + .44f, y_ - 1.15f);
        AddCharToVec('-', x_ + .55f, y_ - 1.15f);
        AddCharToVec('S', x_ + .66f, y_ - 1.15f);
        AddCharToVec('H', x_ + .77f, y_ - 1.15f);
        AddCharToVec('O', x_ + .88f, y_ - 1.15f);
        AddCharToVec('O', x_ + .99f, y_ - 1.15f);
        AddCharToVec('T', x_ + 1.1f, y_ - 1.15f);
        //P - PAUSE
        AddCharToVec('P', x_ , y_ - 1.3f);
        AddCharToVec('-', x_ + .11f, y_ - 1.3f);
        AddCharToVec('P', x_ + .22f, y_ - 1.3f);
        AddCharToVec('A', x_ + .33f, y_ - 1.3f);
        AddCharToVec('U', x_ + .44f, y_ - 1.3f);
        AddCharToVec('S', x_ + .55f, y_ - 1.3f);
        AddCharToVec('E', x_ + .66f, y_ - 1.3f);
        AddCharToVec('G', x_ + .88f, y_ - 1.3f);
        AddCharToVec('A', x_ + .99f, y_ - 1.3f);
        AddCharToVec('M', x_ + 1.1f, y_ - 1.3f);
        AddCharToVec('E', x_ + 1.21f, y_ - 1.3f);
        
        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);

        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices_.size(), vertices_.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    Menu::~Menu(){
        glDeleteBuffers(1, &VBO_);
        glDeleteVertexArrays(1, &VAO_);
    }
    //i is passed based on which menu should be displayed
    void Menu::updateMenu(const int i, const int score_){
        if(i != currentstate_ || score_ != score){
            vertices_.clear();
            currentstate_ = i;
            if(currentstate_ == 0){
                //start menu
                AddCharToVec('C', x_, y_);
                AddCharToVec('A', x_ + .11f, y_);
                AddCharToVec('N', x_ + .22f, y_);
                AddCharToVec('N', x_ + .33f, y_);
                AddCharToVec('O', x_ + .44f, y_);
                AddCharToVec('N', x_ + .55f, y_);
                AddCharToVec('C', x_ + .77f, y_);
                AddCharToVec('R', x_ + .88f, y_);
                AddCharToVec('U', x_ + .99f, y_);
                AddCharToVec('S', x_ + 1.1f, y_);
                AddCharToVec('A', x_ + 1.21f, y_);
                AddCharToVec('D', x_ + 1.32f, y_);
                AddCharToVec('E', x_ + 1.43f, y_);
                AddCharToVec('R', x_ + 1.54f, y_);
                AddCharToVec('S', x_ + 1.65f, y_);
                
                AddCharToVec('S', x_ , y_ - 0.3f);
                AddCharToVec('T', x_ + .11f, y_ - 0.3f);
                AddCharToVec('A', x_ + .22f, y_ - 0.3f);
                AddCharToVec('R', x_ + .33f, y_ - 0.3f);
                AddCharToVec('T', x_ + .44f, y_ - 0.3f);
                AddCharToVec('-', x_ + .55f, y_ - 0.3f);
                AddCharToVec('P', x_ + .66f, y_ - 0.3f);
                AddCharToVec('R', x_ + .77f, y_ - 0.3f);
                AddCharToVec('E', x_ + .88f, y_ - 0.3f);
                AddCharToVec('S', x_ + .99f, y_ - 0.3f);
                AddCharToVec('S', x_ + 1.1f, y_ - 0.3f);
                AddCharToVec('E', x_ + 1.32f, y_ - 0.3f);
                AddCharToVec('N', x_ + 1.43f, y_ - 0.3f);
                AddCharToVec('T', x_ + 1.54f, y_ - 0.3f);
                AddCharToVec('E', x_ + 1.65f, y_ - 0.3f);
                AddCharToVec('R', x_ + 1.76f, y_ - 0.3f);

                AddCharToVec('Q', x_ , y_ - 0.45f);
                AddCharToVec('U', x_ + .11f, y_ - 0.45f);
                AddCharToVec('I', x_ + .22f, y_ - 0.45f);
                AddCharToVec('T', x_ + .33f, y_ - 0.45f);
                AddCharToVec('-', x_ + .44f, y_ - 0.45f);
                AddCharToVec('E', x_ + .55f, y_ - 0.45f);
                AddCharToVec('S', x_ + .66f, y_ - 0.45f);
                AddCharToVec('C', x_ + .77f, y_ - 0.45f);
                

                AddCharToVec('I', x_ , y_ - 0.7f);
                AddCharToVec('N', x_ + .11f, y_ - 0.7f);
                AddCharToVec('-', x_ + .22f, y_ - 0.7f);
                AddCharToVec('G', x_ + .33f, y_ - 0.7f);
                AddCharToVec('A', x_ + .44f, y_ - 0.7f);
                AddCharToVec('M', x_ + .55f, y_ - 0.7f);
                AddCharToVec('E', x_ + .66f, y_ - 0.7f);
                AddCharToVec('C', x_ + .88f, y_ - 0.7f);
                AddCharToVec('O', x_ + .99f, y_ - 0.7f);
                AddCharToVec('N', x_ + 1.1f, y_ - 0.7f);
                AddCharToVec('T', x_ + 1.21f, y_ - 0.7f);
                AddCharToVec('R', x_ + 1.32f, y_ - 0.7f);
                AddCharToVec('O', x_ + 1.43f, y_ - 0.7f);
                AddCharToVec('L', x_ + 1.54f, y_ - 0.7f);
                AddCharToVec('S', x_ + 1.65f, y_ - 0.7f);
                
                //left arrow - MOVE LEFT
                AddCharToVec('<', x_ , y_ - 0.85f);
                AddCharToVec('-', x_ + .05f, y_ - 0.85f);
                AddCharToVec('M', x_ + .21f, y_ - 0.85f);
                AddCharToVec('O', x_ + .32f, y_ - 0.85f);
                AddCharToVec('V', x_ + .43f, y_ - 0.85f);
                AddCharToVec('E', x_ + .54f, y_ - 0.85f);
                AddCharToVec('L', x_ + .76f, y_ - 0.85f);
                AddCharToVec('E', x_ + .87f, y_ - 0.85f);
                AddCharToVec('F', x_ + .98f, y_ - 0.85f);
                AddCharToVec('T', x_ + 1.09f, y_ - 0.85f);

                //right arrow - MOVE RIGHT
                AddCharToVec('-', x_ , y_ - 1.0f);
                AddCharToVec('>', x_ + .05f, y_ - 1.0f);
                AddCharToVec('M', x_ + .21f, y_ - 1.0f);
                AddCharToVec('O', x_ + .32f, y_ - 1.0f);
                AddCharToVec('V', x_ + .43f, y_ - 1.0f);
                AddCharToVec('E', x_ + .54f, y_ - 1.0f);
                AddCharToVec('R', x_ + .76f, y_ - 1.0f);
                AddCharToVec('I', x_ + .87f, y_ - 1.0f);
                AddCharToVec('G', x_ + .98f, y_ - 1.0f);
                AddCharToVec('H', x_ + 1.09f, y_ - 1.0f);
                AddCharToVec('T', x_ + 1.20f, y_ - 1.0f);

                //SPACE - SHOOT
                AddCharToVec('S', x_ , y_ - 1.15f);
                AddCharToVec('P', x_ + .11f, y_ - 1.15f);
                AddCharToVec('A', x_ + .22f, y_ - 1.15f);
                AddCharToVec('C', x_ + .33f, y_ - 1.15f);
                AddCharToVec('E', x_ + .44f, y_ - 1.15f);
                AddCharToVec('-', x_ + .55f, y_ - 1.15f);
                AddCharToVec('S', x_ + .66f, y_ - 1.15f);
                AddCharToVec('H', x_ + .77f, y_ - 1.15f);
                AddCharToVec('O', x_ + .88f, y_ - 1.15f);
                AddCharToVec('O', x_ + .99f, y_ - 1.15f);
                AddCharToVec('T', x_ + 1.1f, y_ - 1.15f);
                //P - PAUSE
                AddCharToVec('P', x_ , y_ - 1.3f);
                AddCharToVec('-', x_ + .11f, y_ - 1.3f);
                AddCharToVec('P', x_ + .22f, y_ - 1.3f);
                AddCharToVec('A', x_ + .33f, y_ - 1.3f);
                AddCharToVec('U', x_ + .44f, y_ - 1.3f);
                AddCharToVec('S', x_ + .55f, y_ - 1.3f);
                AddCharToVec('E', x_ + .66f, y_ - 1.3f);
                AddCharToVec('G', x_ + .88f, y_ - 1.3f);
                AddCharToVec('A', x_ + .99f, y_ - 1.3f);
                AddCharToVec('M', x_ + 1.1f, y_ - 1.3f);
                AddCharToVec('E', x_ + 1.21f, y_ - 1.3f);
            }else if(currentstate_ == 1){
                score = score_;
                AddCharToVec('S', x_, y_);
                AddCharToVec('C', x_ + .11f, y_);
                AddCharToVec('O', x_ + .22f, y_);
                AddCharToVec('R', x_ + .33f, y_);
                AddCharToVec('E', x_ + .44f, y_);
                AddCharToVec('-', x_ + .55f, y_);
                AddIntToVec(score, x_ + 0.66f, y_);
                //in game
            }else if(currentstate_ == 2){
                
                AddCharToVec('P', x_, y_);
                AddCharToVec('A', x_ + .11f, y_);
                AddCharToVec('U', x_ + .22f, y_);
                AddCharToVec('S', x_ + .33f, y_);
                AddCharToVec('E', x_ + .44f, y_);
                AddCharToVec('D', x_ + .55f, y_);
                //press enter to keep playing
                AddCharToVec('R', x_, y_ - .2f);
                AddCharToVec('E', x_ + .11f, y_- .2f);
                AddCharToVec('S', x_ + .22f, y_- .2f);
                AddCharToVec('U', x_ + .33f, y_- .2f);
                AddCharToVec('M', x_ + .44f, y_- .2f);
                AddCharToVec('E', x_ + .55f, y_- .2f);
                AddCharToVec('-', x_ + .66f, y_- .2f);
                AddCharToVec('E', x_ + .77f, y_- .2f);
                AddCharToVec('N', x_ + .88f, y_- .2f);
                AddCharToVec('T', x_ + .99f, y_- .2f);
                AddCharToVec('E', x_ + 1.1f, y_- .2f);
                AddCharToVec('R', x_ + 1.21f, y_- .2f);
                //press M to go to menu
                AddCharToVec('M', x_, y_- .4f);
                AddCharToVec('A', x_ + .11f, y_- .4f);
                AddCharToVec('I', x_ + .22f, y_- .4f);
                AddCharToVec('N', x_ + .33f, y_- .4f);
                AddCharToVec('M', x_ + .44f, y_- .4f);
                AddCharToVec('E', x_ + .55f, y_- .4f);
                AddCharToVec('N', x_ + .66f, y_- .4f);
                AddCharToVec('U', x_ + .77f, y_- .4f);
                AddCharToVec('-', x_ + .88f, y_- .4f);
                AddCharToVec('M', x_ + .99f, y_- .4f);
                
            }else{
                AddCharToVec('G', x_, y_);
                AddCharToVec('A', x_ + .11f, y_);
                AddCharToVec('M', x_ + .22f, y_);
                AddCharToVec('E', x_ + .33f, y_);
                AddCharToVec('O', x_ + .55f, y_);
                AddCharToVec('V', x_ + .66f, y_);
                AddCharToVec('E', x_ + .77f, y_);
                AddCharToVec('R', x_ + .88f, y_);
                //score
                AddCharToVec('S', x_, y_-0.2f);
                AddCharToVec('C', x_ + .11f, y_-0.2f);
                AddCharToVec('O', x_ + .22f, y_-0.2f);
                AddCharToVec('R', x_ + .33f, y_-0.2f);
                AddCharToVec('E', x_ + .44f, y_-0.2f);
                AddCharToVec('-', x_ + .55f, y_-0.2f);
                AddIntToVec(score, x_ + .66f, y_-0.2f);

                //restart
                AddCharToVec('R', x_, y_-0.4f);
                AddCharToVec('E', x_ + .11f,y_ -0.4f);
                AddCharToVec('S', x_ + .22f,y_ -0.4f);
                AddCharToVec('T', x_ + .33f,y_ -0.4f);
                AddCharToVec('A', x_ + .44f,y_ -0.4f);
                AddCharToVec('R', x_ + .55f,y_ -0.4f);
                AddCharToVec('T', x_ + .66f,y_ -0.4f);
                AddCharToVec('-', x_ + .77f,y_ -0.4f);
                AddCharToVec('R', x_ + .88f,y_ -0.4f);
                //main menu
                AddCharToVec('M', x_,y_ -.6f);
                AddCharToVec('A', x_ + .11f,y_ -.6f);
                AddCharToVec('I', x_ + .22f,y_ - .6f);
                AddCharToVec('N', x_ + .33f,y_ - .6f);
                AddCharToVec('M', x_ + .44f,y_ - .6f);
                AddCharToVec('E', x_ + .55f,y_ - .6f);
                AddCharToVec('N', x_ + .66f,y_- .6f);
                AddCharToVec('U', x_ + .77f,y_ - .6f);
                AddCharToVec('-', x_ + .88f,y_ - .6f);
                AddCharToVec('M', x_ + .99f,y_ - .6f);
                //game over
            }
            glBindVertexArray(VAO_);
            glBindBuffer(GL_ARRAY_BUFFER, VBO_);
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * vertices_.size(), vertices_.data());

        }    
    }
    void Menu::renderMenu() const{
          
        glBindVertexArray(VAO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glColor3f(1.0f,1.0f,1.0f);
        int number_quads = vertices_.size() / 8; //each quad has 4 2 point coords
        for(int i = 0; i < number_quads; ++i){
        glDrawArrays(GL_QUADS,i*4,4);
        }
    }   
    //Converts Score into a string and adds to vector to display score to user while playing
    void Menu::AddIntToVec(const int number, float x,const float y){

        std::string numStr = std::to_string(number);
        for (char c : numStr) {
            switch(c){
                case '0':
                    vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right
                    break;
                case '1':
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f); //middle
                    break;
                case '2':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y );
                vertices_.push_back(x + 0.1f); vertices_.push_back(y ); //right side
                    break;
                case '3':
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);//left

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top 

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle
                    break;
                case '4':
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);//right

                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //left

                    break;
                case '5':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right
                    break;
                case '6':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right
                    break;
                case '7':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right
                    break;
                case '8':
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top of A

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle
                    break;
                case '9':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //left

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right

                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle
                    break;
            }
        x+= 0.11f; //so numbers dont overlap
        }
    }
    //adds character to vector
    void Menu::AddCharToVec(const char letter, const float x, const float y){
        switch(letter){
            case 'A':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right

                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle
                break;
            case 'C':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom
                break;

            case 'D':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right
                break;
            case 'E': 
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle
                break;
            case 'F':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle
                break;
            case 'G':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left side

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right
                break;
            case 'H':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right 

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle 
                break;
            case 'I':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x + 0.0375f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f); //middle

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom
                break;
            case 'L':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom
                break;
            case 'M':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0625f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.05f); //left side diag

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.0625f); vertices_.push_back(y - 0.05f); //right side diag

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right 
                break;
            case 'N':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right 

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f); //middle
                break;
            case 'O':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right 
                break;    
            case 'P':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left 

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f); //right

                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle
                break;
            case 'Q':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f); //right
                break;
            case 'R': 
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left 

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f);//top

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f); //right 

                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.06f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right

                vertices_.push_back(x); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x); vertices_.push_back(y - 0.075f); //middle
                break;
            case 'S': 
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right
                break;
            case 'T':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x); vertices_.push_back(y - 0.025f); //top

                vertices_.push_back(x + 0.0375f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f); //middle
                break;
            case 'U':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.075f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x); vertices_.push_back(y - 0.1f);//bottom

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.1f); //right
                break;
            case 'V':
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0625f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f); //left

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0625f); vertices_.push_back(y - 0.1f); //right
                break;
            case 'Y': 
                vertices_.push_back(x); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x); vertices_.push_back(y - 0.05f); //left

                vertices_.push_back(x + 0.1f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f); //right

                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x + 0.0675f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.0375f); vertices_.push_back(y - 0.1f); //middle vertical

                vertices_.push_back(x); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.025f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x); vertices_.push_back(y - 0.05f); //middle horizontal
                break;
            case '-':
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.075f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x + 0.025f); vertices_.push_back(y - 0.0625f); //middle
                break;
            case '<':
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x + 0.05f); vertices_.push_back(y);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x ); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y); //arrow

                break;
            case '>':
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0375f);
                vertices_.push_back(x); vertices_.push_back(y - 0.0625f);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.0625f); //middle

                vertices_.push_back(x + 0.05f); vertices_.push_back(y);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y - 0.1f);
                vertices_.push_back(x + 0.1f); vertices_.push_back(y - 0.05f);
                vertices_.push_back(x + 0.05f); vertices_.push_back(y);//arrow
                break;
        }
    }

}
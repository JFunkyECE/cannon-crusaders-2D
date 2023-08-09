#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace menu{

class Menu{
public:
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu();
    ~Menu();
    void updateMenu(int i, int score_ = 0);
    void renderMenu();
    void AddIntToVec(int number, float x, float y);
    void AddCharToVec(char letter, float x, float y);
        
    


private:
GLuint VAO_, VBO_;
float x_,y_;
int currentstate_;
int score;
std::vector<float> vertices_;
};

}
#endif
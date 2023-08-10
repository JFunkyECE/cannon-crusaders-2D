#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "game.hpp"
#include <vector>
#include <string>

namespace menu{

class Menu{
public:
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu();
    ~Menu();
    void updateMenu(const int i, const int score_ = 0);
    void renderMenu() const;

private:

    void AddIntToVec(const int number, float x, const float y);
    void AddCharToVec(const char letter,const float x,const float y);

    GLuint VAO_, VBO_;
    float x_,y_;
    int currentstate_;
    int score;
    std::vector<float> vertices_;
};

}
#endif
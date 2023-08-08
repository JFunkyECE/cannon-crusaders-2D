#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <string>


namespace menu{

class Menu{
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu();

//start menu
    void renderStartMenu();
//contains the following text
//Title: Cannon Crusaders
//Start: Press ENTER
//Quit: Press Q
//How to Play
//-> move right
//<- move left
//SPACE shoot


//ingame
    void renderInGame();
//enemies left counter thats it

//Pause menu
    void renderPause();
//Small square goes over screen with following text
//Paused
//Press ENTER to continue
//Press R to Restart
//Press M to go back to the menu
//Press Q to quit application


//ENDGAME
    void renderEndGame();
//depending on win or lose
//Great Job or Almost there
//press R to restart
//press M to go back to menu
//press Q to quit application

//render text function 
    void renderText(const std::string& text, float x, float y);
private:
GLuint VAO_, VBO_;
FT_Library ft_;
std::map<char, Character> characters_;
};
}
#endif
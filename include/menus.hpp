#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace menu{

class Menu{
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu(){

    }
//start menu

//contains the following text
//Title: Cannon Crusaders
//Start: Press ENTER
//Quit: Press Q
//How to Play
//-> move right
//<- move left
//SPACE shoot


//ingame

//enemies left counter thats it

//Pause menu

//Small square goes over screen with following text
//Paused
//Press ENTER to continue
//Press R to Restart
//Press M to go back to the menu
//Press Q to quit application


//ENDGAME

//depending on win or lose
//Great Job or Almost there
//press R to restart
//press M to go back to menu
//press Q to quit application
private:
GLuint VAO_, VBO_;
};
}
#endif
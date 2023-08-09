#ifndef game_hpp
#define game_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tank.hpp"
#include "enemy.hpp"
#include <collisiondetection.hpp>
#include <vector>
#include "menus.hpp"

namespace menu {
    class Menu;
}

class Game{

public:

    //be used to indicate to in update what todo
    enum class GameState{
        Start, //initial screen, main menu
        Playing, //in game
        Paused, //in game but paused
        Gameover //game finished, win or lose screen
    };

    Game();
    ~Game();

    void Init();
    void ProcessInput();
    void Update();
    void Render();
    GLFWwindow* getWindow() const;
    void Restart();

private:
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();
    int live_enemies() const;

    GameState current_state;
    GLFWwindow* window_;
    tank::Tank* my_tank;
    menu::Menu* Menu_;
    float lastshot_time;
    float lastspawn_time;        // Last time an enemy was spawned.
    float spawn_interval;        // Time between enemy spawns.
    std::vector<Ducks::Enemy> ducks_;   // List of enemies in the game.
    int enemies_defeated;        // Number of enemies defeated.
    int enemies_on_screen;       // Number of enemies currently on the screen.

};



#endif
#ifndef game_hpp
#define game_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <tank.hpp>
#include <enemy.hpp>
#include <collisiondetection.hpp>
#include <vector>
#include "menus.hpp"

class Game{

public:

    //be used to indicate to in update what todo
    enum class GameState{
        Start, //initial screen, main menu
        Playing, //in game
        Paused, //in game but paused
        Gameover //game finished, win or lose screen
    };

    Game():current_state(GameState::Start), my_tank(nullptr){
        /* Initialize the library */
        if (!glfwInit())
            exit(-1);
        /* Create a windowed mode window and its OpenGL context */
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        window_ = glfwCreateWindow(600, 800, "Cannon Crusaders", NULL, NULL);
        if (!window_){
            glfwTerminate(); //need this hear because after initialization
            exit(-1);
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window_);
            glewExperimental = GL_TRUE;
            if (glewInit() != GLEW_OK) {
                std::cout << "Failed to initialize GLEW" << std::endl;
                exit(-1);
            }
        my_tank = new tank::Tank(); 
        Menu_ = new menu::Menu();
        ducks_.reserve(50); //reserve enough space for duck objects
        ducks_.clear();
        lastshot_time = 0.0f;
        current_state = GameState::Start; //change back to start page eventually 
        lastspawn_time = 0.0f; 
        spawn_interval = 1.5f; // to make sure enemies dont spawn in too quick succession
        enemies_defeated = 0; //records # of shots fired
        enemies_on_screen = 0;
        game_over = false;
    }


    ~Game() {
       delete my_tank;
       delete Menu_;
       glfwDestroyWindow(window_);
       glfwTerminate();
    }

    //resets gamestate and data associated with game
    void Init(){
        // Reset the tank
        delete my_tank;
        my_tank = new tank::Tank();  // This creates a new tank object, effectively resetting it
        Menu_->updateMenu(0);
        // Reset other game variables
        ducks_.clear();
        lastshot_time = 0.0f;
        current_state = GameState::Start; //change back to start page eventually 
        lastspawn_time = 0.0f; 
        spawn_interval = 1.5f; // to make sure enemies dont spawn in too quick succession
        enemies_defeated = 0; //records # of shots fired
        enemies_on_screen = 0;
        game_over = false;
    }

    //processes keyboard inputs depending on what state the game is in
    void ProcessInput(){
        switch (current_state) {
            case GameState::Start:
                if (glfwGetKey(window_, GLFW_KEY_ENTER) == GLFW_PRESS) {
                    Init(); //ensures data resets    
                    current_state = GameState::Playing;
                }
                break;

            case GameState::Playing:
                if (glfwGetKey(window_, GLFW_KEY_LEFT) == GLFW_PRESS) {
                    my_tank->move(-0.025f);  // Move the tank to the left
                }
                if (glfwGetKey(window_, GLFW_KEY_RIGHT) == GLFW_PRESS) {
                    my_tank->move(0.025f);  // Move the tank to the right
                }
                if (glfwGetKey(window_, GLFW_KEY_SPACE) == GLFW_PRESS) {
                    float current_time = glfwGetTime(); //gives time in seconds
                    if(current_time - lastshot_time >= 0.05f){ //limit shooting to one per 0.2 seconds or 5 shots per second
                        my_tank->shoot();
                        lastshot_time = current_time;
                    }
                }
                if (glfwGetKey(window_, GLFW_KEY_P) == GLFW_PRESS) {
                    current_state = GameState::Paused; // Pause the game
                }
                break;

            case GameState::Paused:
                if (glfwGetKey(window_, GLFW_KEY_ENTER) == GLFW_PRESS) {
                    current_state = GameState::Playing; 
                }
                if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                    current_state = GameState::Start; // Resume the game
                }
                break;

            case GameState::Gameover:
                if (glfwGetKey(window_, GLFW_KEY_R) == GLFW_PRESS) {
                    Restart();
                }
                break;
        }
    }
        

    // add input for pausing game

    void Update(){
        collisions::CollisionDetection detector;
        ProcessInput();
        //Menu_.updateMenu();
        switch (current_state) {
            
            case GameState::Start:
                //implement startmenu function that displays start menu info
                
                break;
            case GameState::Playing:
                // Normal game update logic
                //check for collisions here
                //check for game ending duck movement
                spawnEnemy();
                my_tank->updateCannonballs();
                updateEnemies();
                detector.Hit_Duck(ducks_, my_tank, enemies_defeated, enemies_on_screen);
                if(enemies_defeated == 50){
                    outcome = true;
                    game_over = true;
                }
                if(game_over == true || detector.Hit_Tank(ducks_, my_tank)){
                    current_state = GameState::Gameover;
                    if(outcome == false){
                        std::cout << "loser" << std::endl;
                    }else{
                        std::cout << "winner" << std::endl;                        
                    }
                }
                break;
            case GameState::Paused:
                // Display a pause menu
                //menu::pausemenu();
                break;
            case GameState::Gameover:
                // Display game over screen
                //menu::gameover()
                break;
        }
    }
    void Render(){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
        //create menu object here
        switch (current_state) {
            case GameState::Start:
                Menu_->renderMenu();
                break;
            case GameState::Playing:
               my_tank->render();
               my_tank->renderCannonballs();
               renderEnemies();
               //Menu_.renderMenu(1);
                break;
            case GameState::Paused:
                //Menu_.renderMenu(2);
                break;
            case GameState::Gameover:
                //Menu_.renderMenu(3);
                break;
        }
        

        //add cases for different playing states
    }

    GLFWwindow* getWindow() const {
        return window_;
    } 

    void Restart(){
        Init();
        current_state = GameState::Playing;
    } //for when player wants to restart game


    void spawnEnemy(){
        if (live_enemies() < 5 && glfwGetTime() - lastspawn_time > spawn_interval) {
            ducks_.emplace_back();
            enemies_on_screen++;
            lastspawn_time = glfwGetTime();
        }}
    void updateEnemies(){
        //movement algorithm for enemy objects
        //start with just moving straight down
        for (auto it = (ducks_.begin()); it != ducks_.end(); ++it) {
            if (it->isActive()) {
                it->move(-0.015f);
                // Check if the duck has gone off the bottom of the screen
                if (it->getY() < -1.0f) {
                    game_over = true;
                    outcome = false;
                }
            } 
        }
    }
    void renderEnemies(){
        for(int i = enemies_defeated; i < ducks_.size(); ++i) {
            if(ducks_[i].isActive()){
                ducks_[i].render();
            }
        }
    }
    int live_enemies() const{
        int count = 0;
        for (const Ducks::Enemy& duckss : ducks_) {
        if (duckss.isActive()) {
            ++count;
        }
        }
        return count; 
    }


private:
GameState current_state;
GLFWwindow* window_;
tank::Tank* my_tank;
menu::Menu* Menu_;
float lastshot_time;
float lastspawn_time; //makes sure enemies spawn in reasonable time of one another
float spawn_interval; // to make sure enemies dont spawn in too quick succession
std::vector<Ducks::Enemy> ducks_; //stores cannonball data
int enemies_defeated; //for completion of game purpose
int enemies_on_screen;
bool game_over;
bool outcome;
};



#endif
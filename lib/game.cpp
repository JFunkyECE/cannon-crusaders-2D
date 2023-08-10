#include "../include/game.hpp"
#include <iostream>

    Game::Game():current_state(GameState::Start), my_tank(nullptr){
        if (!glfwInit()){
            exit(-1);
        }
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        window_ = glfwCreateWindow(800, 800, "Cannon Crusaders", NULL, NULL);
        if (!window_){
            glfwTerminate();
            exit(-1);
        }

        glfwMakeContextCurrent(window_);
            glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            std::cout << "Failed to initialize GLEW" << std::endl;
            exit(-1);
        }
        my_tank = new tank::Tank(); 
        Menu_ = new menu::Menu();
        ducks_.reserve(50); 
        ducks_.clear();
        lastshot_time = 0.0f;
        current_state = GameState::Start; 
        lastspawn_time = 0.0f; 
        spawn_interval = 1.5f; 
        enemies_defeated = 0; 
        enemies_on_screen = 0;
    }


    Game::~Game() {
       delete my_tank;
       delete Menu_;
       glfwDestroyWindow(window_);
       glfwTerminate();
    }

    //resets data members associated with game
    void Game::Init(){
        // Reset the tank
        delete my_tank;
        my_tank = new tank::Tank(); 
        Menu_->updateMenu(0);
        // Reset other game variables
        ducks_.clear();
        lastshot_time = 0.0f;
        current_state = GameState::Start; 
        lastspawn_time = 0.0f; 
        spawn_interval = 1.5f; 
        enemies_defeated = 0; 
        enemies_on_screen = 0;
    }

    //processes keyboard inputs depending on what state the game is in
    void Game::ProcessInput(){
        switch (current_state) {
            case GameState::Start:
                if (glfwGetKey(window_, GLFW_KEY_ENTER) == GLFW_PRESS) {
                    Init(); //data reset    
                    current_state = GameState::Playing;
                }
                if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                    //quits application
                    glfwSetWindowShouldClose(window_, 1);
                }
                break;

            case GameState::Playing:
                if (glfwGetKey(window_, GLFW_KEY_LEFT) == GLFW_PRESS) {
                    my_tank->move(-0.030f);  // Move the tank to the left
                }
                if (glfwGetKey(window_, GLFW_KEY_RIGHT) == GLFW_PRESS) {
                    my_tank->move(0.030f);  // Move the tank to the right
                }
                if (glfwGetKey(window_, GLFW_KEY_SPACE) == GLFW_PRESS) {
                    float current_time = glfwGetTime(); 
                    if(current_time - lastshot_time >= 0.15f){ //limit shooting to one per 0.15 seconds
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
                    current_state = GameState::Playing; //Reumse
                }
                if (glfwGetKey(window_, GLFW_KEY_M) == GLFW_PRESS) {
                    current_state = GameState::Start; // Main Menu
                }
                break;

            case GameState::Gameover:
                if (glfwGetKey(window_, GLFW_KEY_R) == GLFW_PRESS) {
                    Restart(); //Restart Game
                }
                if (glfwGetKey(window_, GLFW_KEY_M) == GLFW_PRESS) {
                    current_state = GameState::Start; // Resume the game
                }
                break;
        }
    }
        


    void Game::Update(){
        collisions::CollisionDetection detector;
        ProcessInput();
        switch (current_state) {
            case GameState::Start:
                Menu_->updateMenu(0);
                break;
            case GameState::Playing:
                //check for collisions
                //check for game ending duck movement
                //update object positions
                Menu_->updateMenu(1,enemies_defeated);
                spawnEnemy();
                my_tank->updateCannonballs();
                updateEnemies();
                detector.Hit_Duck(ducks_, my_tank, enemies_defeated, enemies_on_screen);
                if(detector.Hit_Tank(ducks_, my_tank)){
                    current_state = GameState::Gameover;
                }
                break;
            case GameState::Paused:
                Menu_->updateMenu(2,enemies_defeated);
                break;
            case GameState::Gameover:
                Menu_->updateMenu(3,enemies_defeated);
                break;
        }
    }
    void Game::Render(){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
        switch (current_state) {
            case GameState::Start:
                Menu_->renderMenu();
                break;
            case GameState::Playing:
                my_tank->render();
                my_tank->renderCannonballs();
                renderEnemies();
                Menu_->renderMenu();
                break;
            case GameState::Paused:
                Menu_->renderMenu();
                break;
            case GameState::Gameover:
                Menu_->renderMenu();
                break;
        }
        }

    GLFWwindow* Game::getWindow() const {
        return window_;
    } 

    void Game::Restart(){
        Init();
        current_state = GameState::Playing;
    } //for when player wants to restart game


    void Game::spawnEnemy(){
        //this clears non active objects in ducks_ once full
        if(enemies_defeated % 50 == 0 && enemies_defeated != 0){
            if(enemies_on_screen == 0){
            ducks_.clear();
            }
        }
        //Never more than 5 enemies on screen
        if (live_enemies() < 5 && glfwGetTime() - lastspawn_time > spawn_interval) {
            ducks_.emplace_back();
            std::cout <<spawn_interval<< std::endl;
            enemies_on_screen++;
            lastspawn_time = glfwGetTime();
            spawn_interval = 1.5f - enemies_defeated/100.0f;
            std::cout << spawn_interval <<std::endl;
        // if(enemies_defeated > 10){
        //     spawn_interval = 1.2f;
        // }
        // if(enemies_defeated > 20){
        //     spawn_interval = 1.0f;
        // }
        // if(enemies_defeated > 40){
        //     spawn_interval = 0.9f;
        // }
        // if(enemies_defeated > 50){
        //     spawn_interval = 0.75f;
        // }
        // if(enemies_defeated > 75){
        //     spawn_interval = 0.5f;
        // }
        }
    }
    void Game::updateEnemies(){
        //movement algorithm for enemy objects
        for (auto it = (ducks_.begin()); it != ducks_.end(); ++it) {
            if (it->isActive()) {
                it->move(-0.015f);
                // Check if the duck has gone off the bottom of the screen, game ending
                if (it->getY() < -1.0f) {
                    current_state = GameState::Gameover;
                }
            } 
        }
    }
    void Game::renderEnemies(){
        for(int i = 0; i < ducks_.size(); ++i) {
            if(ducks_[i].isActive()){
                ducks_[i].render();
            }
        }
    }
    int Game::live_enemies() const{
        int count = 0;
        for (const Ducks::Enemy& duckss : ducks_) {
        if (duckss.isActive()) {
            ++count;
        }
        }
        return count; 
    }


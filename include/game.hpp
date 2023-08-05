#ifndef game_hpp
#define game_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <tank.hpp>
#include <vector>

class Game{

public:

    //be used to indicate to in update what todo
    enum class GameState{
        Start, //initial screen, main menu
        Playing, //in game
        Paused, //in game but paused
        Gameover //game finished, win or lose screen
    };

    Game():current_state(GameState::Playing), my_tank(nullptr){
        /* Initialize the library */
        if (!glfwInit())
            exit(-1);
        /* Create a windowed mode window and its OpenGL context */
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
        my_tank = new tank::Tank();  // This creates a new tank object, effectively resetting it

        Init();
    }


    ~Game() {
       delete my_tank;
       glfwTerminate();
    }

    //resets gamestate and data associated with game
    void Init(){
        // Reset the tank
        delete my_tank;
        my_tank = new tank::Tank();  // This creates a new tank object, effectively resetting it

        // Reset other game variables
        lastshot_time = 0.0f;
        current_state = GameState::Playing; //will change back to start, just to make sure it works right now
    }

    //processes keyboard inputs
    void ProcessInput(){
        if (glfwGetKey(window_, GLFW_KEY_LEFT) == GLFW_PRESS) {
            my_tank.move(-0.01f);  // Move the tank to the left
        }
        if (glfwGetKey(window_, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            my_tank.move(0.01f);  // Move the tank to the right
        }
        if (glfwGetKey(window_, GLFW_KEY_SPACE) == GLFW_PRESS) {
            float current_time = glfwGetTime(); //gives time in seconds
            if(current_time - lastshot_time >= 0.2f){ //limit shooting to one per 0.2 seconds or 5 shots per second
                my_tank.shoot();
                lastshot_time = current_time;
            }
        }

    // add input for pausing game
    }
    void Update(){

        ProcessInput();

        switch (current_state) {
            case GameState::Start:
                // Maybe display a start screen or instructions
                break;
            case GameState::Playing:
                // Normal game update logic
                my_tank->updateCannonballs();
                break;
            case GameState::Paused:
                // Display a pause menu
                break;
            case GameState::Gameover:
                // Display game over screen
                break;
        }
    }
    void Render(){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.5f, 0.0f, 1.0f); // Set clear color to green
       
        my_tank->render();
        my_tank->renderCannonballs();
    }

    GLFWwindow* getWindow() const {
        return window_;
    } 

    void Run();
    void Restart(); //for when player wants to restart game

private:
GameState current_state;
GLFWwindow* window_;
tank::Tank* my_tank;
float lastshot_time;
//add member class for enemies

};



#endif
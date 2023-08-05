#ifndef game_hpp
#define game_hpp


class Game{

public:

    //be used to indicate to in update what todo
    enum class GameState{
        Start,
        Playing,
        Paused,
        Gameover
    };

    Game();


    ~Game();

    void Init();
    void ProcessInput();
    void Update();
    void Render();
    void Run();

private:



};



#endif
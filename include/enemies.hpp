#ifndef enemies_hpp
#define enemies_hpp

namespace ducks{

//create enemy class that holds a vector of enemies with information about current position 

class Enemies{

public:

    //need constructor that reserves based on difficulty, ie either 20 or 50 enemies.
    Enemies(int number_of_enemies): enemies_remaining(number_of_enemies){

    }
    //destructor
    ~Enemies();

    //where the movement algorithm will be implemented
    void move();

    float getX();
    float getY();

    bool exists();

    bool check_collision();

private:
int enemies_remaining;
};



}
#endif
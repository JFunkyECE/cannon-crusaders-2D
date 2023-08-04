#ifndef cannonballs_hpp
#define cannonballs_hpp

class Cannonballs {

public:
    //constructor that makes cannonball at current location of cannon
    Cannonballs(float x, float y): x_(x), y_(y), exists_(true){

    }

private:
float x_,y_; //stores key data related to position of ball
bool exists_; //stores whether bullet has made contact with enemy or is out of window
};


#endif
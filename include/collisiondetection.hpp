#ifndef collisiondetection_hpp
#define collisiondetection_hpp
#include "game.hpp"
#include "tank.hpp"
#include "enemy.hpp"
#include "cannonballs.hpp"
#include <iostream>

namespace collisions{

class CollisionDetection{
public:
//first function checks whether bullets have made contact with ducks
//three parameters: duck vector, tank object, and enemies defeated counter
void Hit_Duck(std::vector<Ducks::Enemy>& ducks_, tank::Tank* my_tank, int& enemies_defeated, int enemies_on_screen){
    //loop through bullets, checking if active before continuing
    for(Cannonballs& cannonball : my_tank->Cannonballpositions()){
        if(cannonball.exists()){
            for(Ducks::Enemy& duck: ducks_){
                if(duck.isActive()){
                    //detect collision between them here
                    
                    if(Collision_detected(duck,cannonball)){
                        duck.setActive(false);
                        ++enemies_defeated;
                        --enemies_on_screen;
                        std::cout << "enemies defeated " << enemies_defeated << std::endl;
                        cannonball.setExists(false);
                    }
                }
            }
        }
    }

}

bool Collision_detected(const Ducks::Enemy& duck, const Cannonballs& cannonball){
    //for duck we use two hitboxes, one for the body and one for the beak, both will be represented by rectangles
    float x_duck = duck.getX();
    float y_duck = duck.getY();
    
    //beak and body variables
    float w_beak = 0.04f;
    float h_beak = 0.05f;
    float x_beak = x_duck;
    float y_beak = y_duck - 0.05f;

    float w_body = 0.11f;
    float h_body = 0.15f;
    float x_body = x_duck + 0.04f;
    float y_body = y_duck;

    float wh_cannonball = 0.04f;
    float x_cannonball = cannonball.getX();
    float y_cannonball = cannonball.getY();

    //AABB collision detection
    bool beak = (x_cannonball < x_beak + w_beak &&
                 x_cannonball + wh_cannonball > x_beak &&
                 y_cannonball < y_beak + h_beak &&
                 y_cannonball + wh_cannonball > y_beak);
    
    bool body = (x_cannonball < x_body + w_body &&
                 x_cannonball + wh_cannonball > x_body &&
                 y_cannonball < y_body + h_body &&
                 y_cannonball + wh_cannonball > y_body);
    return beak || body;
}
//second function checks whether a ducks has reached the end or if duck has made contact with tank
//if this returns true then we stop the program becuase the user has lost.
//two parameters: duck vector, and tank object
//void Hit_Tank(){}
};
}

#endif
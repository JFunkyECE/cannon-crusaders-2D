#include "../include/collisiondetection.hpp"

namespace collisions{

//Updates enemies_defeated and enemies_on_screen if
//a collision is detected between a cannonball and a
//duck. Both contacting parties derender after colliding.
void CollisionDetection::Hit_Duck(std::vector<Ducks::Enemy>& ducks_, tank::Tank* my_tank, int& enemies_defeated, int& enemies_on_screen){
    //loop through bullets, checking if active before continuing
    for(Cannonballs& cannonball : my_tank->Cannonballpositions()){
        if(cannonball.exists()){
            for(Ducks::Enemy& duck: ducks_){
                if(duck.isActive()){
                    
                    if(Collision_detected(duck,cannonball)){
                        duck.setActive(false);
                        ++enemies_defeated;
                        --enemies_on_screen;
                        cannonball.setExists(false);
                    }
                }
            }
        }
    }

}

//Ends the game if a collision is detected between
//a duck and the users tank.
bool CollisionDetection::Hit_Tank(std::vector<Ducks::Enemy>& ducks_, tank::Tank* my_tank){

    //iterate through duck objects, checking whether they make contact with the tank
    for(Ducks::Enemy& duck: ducks_){
            if(duck.isActive()){
                if(Collision_detected(duck,my_tank)){
                    return true;
                }
            }
    }
    return false;
}

//helper function for Hit_Tuck
bool CollisionDetection::Collision_detected(const Ducks::Enemy& duck, const Cannonballs& cannonball){
    //for duck we use two hitboxes for the body for the beak,
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

//helper function for Hit_Tank
bool CollisionDetection::Collision_detected(const Ducks::Enemy& duck, const tank::Tank* my_tank){
    //for duck we use two hitboxes for the body for the beak,
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
    //tank vertices
    float w_tank = 0.20f;
    float h_tank = 0.25f;
    float x_tank = my_tank->getX();
    float y_tank = my_tank->getY();

    //AABB collision detection
    bool beak = (x_tank < x_beak + w_beak &&
                 x_tank + w_tank > x_beak &&
                 y_tank < y_beak + h_beak &&
                 y_tank + h_tank > y_beak);
    
    bool body = (x_tank < x_body + w_body &&
                 x_tank + w_tank > x_body &&
                 y_tank < y_body + h_body &&
                 y_tank + h_tank > y_body);
                 
    return (beak || body);
}
}
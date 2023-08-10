#ifndef collisiondetection_hpp
#define collisiondetection_hpp
#include "game.hpp"
#include "tank.hpp"
#include "enemy.hpp"
#include "cannonballs.hpp"

namespace collisions{

class CollisionDetection{
public:

//detects collisions between cannonballs and enemy objects
void Hit_Duck(std::vector<Ducks::Enemy>& ducks_, tank::Tank* my_tank, int& enemies_defeated, int& enemies_on_screen);

//detects collision between tank and duck
bool Hit_Tank(std::vector<Ducks::Enemy>& ducks_, tank::Tank* my_tank);

private:
//helper functions for detection collisions
bool Collision_detected(const Ducks::Enemy& duck, const Cannonballs& cannonball);
bool Collision_detected(const Ducks::Enemy& duck, const tank::Tank* my_tank);
};
}

#endif
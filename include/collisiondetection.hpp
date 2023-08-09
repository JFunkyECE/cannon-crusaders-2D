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
void Hit_Duck(std::vector<Ducks::Enemy>& ducks_, tank::Tank* my_tank, int& enemies_defeated, int& enemies_on_screen);

bool Collision_detected(const Ducks::Enemy& duck, const Cannonballs& cannonball);
//second function checks whether a ducks has reached the end or if duck has made contact with tank
//if this returns true then we stop the program becuase the user has lost.
//two parameters: duck vector, and tank object
bool Hit_Tank(std::vector<Ducks::Enemy>& ducks_, tank::Tank* my_tank);

bool Collision_detected(const Ducks::Enemy& duck, const tank::Tank* my_tank);
};
}

#endif
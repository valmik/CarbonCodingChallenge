#ifndef ROBOT_H_
#define ROBOT_H_

#include "world.h"

// Forward declaration
class World;

// Define and implement the following class
class Robot {
 public:
  Robot(char name);

  /**
    Returns a random move
  */
  char randomMove();

  /**
    get method
  */
  char getName();

  /**
    takes in a world and moves the robot
    Preference is w, a, s, d
  */
  void moveRobot(World &world);

 private:
  char name_;
};

#endif

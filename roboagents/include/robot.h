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
  char getMove();

  /**
    get method
  */
  char getName();

 private:
  char name_;
};

#endif

#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <tuple>
#include <map>
#include <thread>
#include <mutex>
#include "robot.h"

// Forward declaration
class Robot;

// Define and implement the following class. Feel free to change the given
// interfaces and data structures to better match your design
class World {

 public:
  /**
    Constructor for the World object.
    Takes in a vector of (x, y) tuples representing obstacle coordinates
    Takes in two integers sizeX and sizeY for the size of the world

    I had the constructor create the map from scratch because I wanted
    to use a vector of vectors. Since I couldn't use static arrays 
    because I wanted to be able to set the size, and using a template 
    would make me get rid of the nice header file, I felt vectors were the
    best option. However, since they're dynamic, I didn't want a user to 
    input a badly-formatted map (with one row longer than the others, for example)
    Therefore, I decided to create it myself, so the code can guarantee proper sizing.
  */
  World(std::vector<std::tuple<int, int> > obstacles, int sizeX, int sizeY);
  
  /**
    Robots are identified by a char identifier
    If the char already exists, the world will remove the already-existing
    robot and replace it in the new location, if able. If unable, the robot
    will remain where it originally was
  */
  bool addRobot(int row, int col, char name);

  /**
    Move the robot identified by char name in a direction defined by
    w - up
    a - left
    s - down
    d - right

    If the robot does not exist, or the move is not possible, the function will
    return false
  */
  bool moveRobot(char name, char direction);

  /**
    Runs the display thread infinitely
  */
  void run();

  /**
    Displays the map in ASCII
  */
  void display();

 private:
  World(const World& that) = delete;

  // Add a mutex which we use in the moveRobot function
  std::mutex mutex;

  std::vector<std::vector<char> > map_;
  std::map<char, std::tuple<int, int> > robots_;
};

#endif

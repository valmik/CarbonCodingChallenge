#include "world.h"
#include "robot.h"

#include <iostream>
#include <chrono>


// /**
//   Creates a robot at (x, y), then has it move continuosly
//   This will be run in a parallel thread
//   Returns false if it can't make the robot
// */
// void makeAndMove(char name, int x, int y, World &w) {
//   Robot rob(name);
//   if (w.addRobot(x, y, name)) {
//     while(true) {
//       w.moveRobot(name, rob.getMove());
//     }
//   }
// }

int main(int argc, char** argv) {
  // You should customize this data structure and the World constructor to
  // match your chosen data structure.

  srand(10);

  // Define the size of our world
  int sizeX = 10;
  int sizeY = 8;

  // Define the number of obstacles
  int numObstacles = 10;

  // Create a vector containing tuples of the obstacles
  std::vector<std::tuple<int, int> > obstacles(numObstacles);
  for (int i = 0; i < numObstacles; i++) {
      obstacles[i] = std::make_tuple(rand()%sizeX, rand()%sizeY);
  }

  World w(obstacles, sizeX, sizeY);

  // std::thread r1(makeAndMove, 'A', 1, 1, w);

  Robot r1('A');
  w.addRobot(1, 1, 'A');

  Robot r2('B');
  w.addRobot(1, 2, 'B');

  std::thread t1([&w, &r1]{
      while(true) {
        w.moveRobot('A', r1.getMove());
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
      });

  std::thread t2([&w, &r2]{
      while(true) {
        w.moveRobot('B', r2.getMove());
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
      });

  // std::thread r2(makeAndMove, 'B', 1, 2, w);

  // w.display();
  w.run();

  t1.join();
}

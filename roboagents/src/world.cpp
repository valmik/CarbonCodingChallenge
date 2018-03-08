#include <iostream>
#include <chrono>
#include "world.h"

World::World(std::vector<std::tuple<int, int> > obstacles, int sizeX, int sizeY) {

  // Min size must be 1x1
  if(sizeX < 1) {
    sizeX = 1;
  }
  if(sizeY < 1) {
    sizeY = 1;
  }

  // Create map
  map_ = std::vector<std::vector<char> >(sizeX);

  // Populate outer wall with ones and the rest with zeros
  for (int i = 0; i < sizeX; i++) {
    map_[i] = std::vector<char>(sizeY);
    for (int j = 0; j < sizeY; j++) {
      if (i == 0 || i == sizeX-1 || j == 0 || j == sizeY-1) {
        map_[i][j] = '1';
      }
      else {
        map_[i][j] = '0';
      }
    }
  }

  // Populate the obstacles
  for (int i = 0; i < obstacles.size(); i++) {

    // Eliminate out-of-bounds obstacles
    if (std::get<0>(obstacles[i]) < sizeX && std::get<0>(obstacles[i]) >= 0
        && std::get<1>(obstacles[i]) < sizeY && std::get<1>(obstacles[i]) >= 0 ) {
    
      map_[std::get<0>(obstacles[i])][std::get<1>(obstacles[i])] = '1';
    }
  }
}

bool World::addRobot(int row, int col, char name) {
  // Make sure robot is in bounds
  if (row >= map_.size() || col>=map_[0].size()) {
    return false;
  }
  // Make sure placement is empty
  if (map_[row][col] == '0') {
    map_[row][col] = name;

    // If the robot already exists, remove it from the map
    if(robots_.count(name)) {
      map_[std::get<0>(robots_[name])][std::get<1>(robots_[name])] = '0';
    }

    // Note its (x, y) position
    robots_[name] = std::make_tuple(row, col);
    return true;
  }
  else {
    return false;
  }
}

bool World::moveRobot(char name, char direction) {
  
  // Lock guard to unlock mutex even if there's an error
  std::lock_guard<std::mutex> lockGuard(mutex);

  if(robots_.count(name)) {
    int x = std::get<0>(robots_[name]);
    int y = std::get<1>(robots_[name]);
    if (direction == 'a') {
      if (map_[x][y-1] == '0') {
        map_[x][y] = '0';
        y = y-1;
        // std::cout << 'w';
      } else {
        return false;
      }
    }
    else if (direction == 'w') {
      if (map_[x-1][y] == '0') {
        map_[x][y] = '0';
        x = x-1;
        // std::cout << 'a';
      } else {
        return false;
      }
    }
    else if (direction == 'd') {
      if (map_[x][y+1] == '0') {
        map_[x][y] = '0';
        y = y+1;
        // std::cout << 's';
      } else {
        return false;
      }
    }
    else if (direction == 's') {
      if (map_[x+1][y] == '0') {
        map_[x][y] = '0';
        x = x+1;
        // std::cout << 'd';
      } else {
        return false;
      }
    }
    
    robots_[name] = std::make_tuple(x, y);
    map_[x][y] = name;
    return true;
  }
  else {
    return false;
  }
}


void World::run() {
  while (true) {
    display();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void World::display() {
  // "Clear" screen
  for (int i = 0; i < 20; i++)
    std::cout << std::endl;
  for (int i = 0; i < map_.size(); i++) {
    for (int j = 0; j < map_[0].size(); j++) {
      std::cout << map_[i][j];
    }
    std::cout << std::endl;
  }
}

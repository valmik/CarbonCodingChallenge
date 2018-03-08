#include "robot.h"
#include "stdlib.h"

Robot::Robot(char name) {
    name_ = name;
}

char Robot::randomMove() {
    char moves[4] = {'w', 'a', 's', 'd'};
    return moves[rand()%4];
}


void Robot::moveRobot(World &world) {
    if (world.moveRobot(name_, 'w')) {
        return;
    }
    if (world.moveRobot(name_, 'a')) {
        return;
    }
    if (world.moveRobot(name_, 's')) {
        return;
    }
    if (world.moveRobot(name_, 'd')) {
        return;
    }
    return;
}

char Robot::getName() {
    return name_;
}

#include "robot.h"
#include "stdlib.h"

Robot::Robot(char name) {
    name_ = name;
}

char Robot::getMove() {
    char moves[4] = {'w', 'a', 's', 'd'};
    return moves[rand()%4];
}

char Robot::getName() {
    return name_;
}

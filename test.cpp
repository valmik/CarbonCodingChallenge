#include <vector>
#include <iostream>
#include <tuple>


int main() {
    int sizeX = 10;
    int sizeY = 8;
    int numObstacles = 10;

    srand(10);

    std::vector<std::tuple<int, int> > obstacles(numObstacles);
    for (int i = 0; i < numObstacles; i++) {
        obstacles[i] = std::make_tuple(rand()%sizeX, rand()%sizeY);
    }

    // std::cout << obstacles.size() << "\n";

    // for (int i = 0; i < 10; i++) {
    //     std::cout << std::get<0>(obstacles[i]) << ", " << std::get<1>(obstacles[i]) << "\n";
    // }



    std::vector<std::vector<char> > map_(sizeX);

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

    for (int i = 0; i < obstacles.size(); i++) {
        map_[std::get<0>(obstacles[i])][std::get<1>(obstacles[i])] = '1';
    }

    for (int i = 0; i < map_.size(); i++) {
        for (int j = 0; j < map_[0].size(); j++) {
            std::cout << map_[i][j];
        }
        std::cout << std::endl;
    }
}


#ifndef OBIEKTOWECPP_WORLD_H
#define OBIEKTOWECPP_WORLD_H
#include <vector>
#include <iostream>
#include <ctime>


class Organism;


class World {
private:
    int height, width, turn = 1,cooldown=0;
    bool game_status = 1;
public:
    std::vector<std::vector<Organism*>> Organisms;
    std::vector<std::vector<char>> Board;
    World(int height, int width);

    void drawWorld();

    void placeRandomOnPosition(Organism *organism);

    void setGameStatus(bool status);

    bool getGameStatus() const;

    void makeTurn();

    void setCooldown(int cooldown);

    int getCooldown();

    int getTurn();

    int getHeight() const;

    int getWidth() const;
    bool isPositionEmptyAndValid(int x, int y);
    void addOrganism(Organism *organism, int x, int y);
};
#endif //OBIEKTOWECPP_WORLD_H

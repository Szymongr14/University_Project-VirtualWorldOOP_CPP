#ifndef OBIEKTOWECPP_WORLD_H
#define OBIEKTOWECPP_WORLD_H
#include <vector>
#include <iostream>
#include <ctime>
#include <string>


class Organism;


class World {
private:
    int height, width, turn = 1,cooldown=0;
    bool game_status = true;
    int humanAbilityTime = 0;
    std::vector<std::vector<Organism*>> Organisms;
    std::vector<std::vector<std::string>> Board;
public:
    World(int height, int width);

    //constructor for loading world from file
    World(const char * fileName);

    void drawWorld();

    void placeRandomOnPosition(Organism *organism);

    void setGameStatus(bool status);

    bool getGameStatus() const;

    int getHumanAbilityTime() const;

    void setHumanAbilityTime(int humanAbilityTime);

    void makeTurn();

    void setCooldown(int cooldown);

    int getCooldown() const;

    int getTurn() const;

    int getHeight() const;

    int getWidth() const;
    bool isPositionEmptyAndValid(int x, int y);
    bool isPositionValid(int x, int y) const;
    void addOrganism(Organism *organism, int x, int y);
    void removeOrganism(Organism *organism);
    void moveOrganism(Organism *organism, int x, int y);

    Organism* getOrganism(int x, int y);

    int returnEmptyPositionAround(int x, int y);

    void escapeToPosition(Organism *organism, int x, int y);

    void saveWorld(const char *fileName);
    void placeOnPosition(Organism *organism, int x, int y);

    void updateBoard();
};
#endif //OBIEKTOWECPP_WORLD_H

//
// Created by szymo on 08.04.2023.
//

#ifndef UNTITLED_LIS_H
#define UNTITLED_LIS_H
#include "Animal.h"


class Lis :public Animal{
public:
    Lis(World *currentWorld, int positionX, int positionY, int age);
    Lis(World *currentWorld, int initative, int strength, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
    Organism *clone() override;
};


#endif //UNTITLED_LIS_H

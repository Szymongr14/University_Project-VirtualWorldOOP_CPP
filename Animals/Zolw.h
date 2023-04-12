//
// Created by szymo on 08.04.2023.
//

#ifndef UNTITLED_ZOLW_H
#define UNTITLED_ZOLW_H
#include "Animal.h"


class Zolw :public Animal{
public:
    Zolw(World *currentWorld, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
    Organism * clone()override;

};


#endif //UNTITLED_ZOLW_H

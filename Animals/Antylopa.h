//
// Created by szymo on 07.04.2023.
//

#ifndef UNTITLED_ANTYLOPA_H
#define UNTITLED_ANTYLOPA_H


#include "Animal.h"

class Antylopa : public Animal{
public:
    Antylopa(World *currentWorld, int positionX, int positionY, int age);
    Antylopa(World *currentWorld, int initative, int strength, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
    Organism * clone() override;
};


#endif //UNTITLED_ANTYLOPA_H

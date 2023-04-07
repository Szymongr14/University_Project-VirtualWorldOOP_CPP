//
// Created by szymo on 07.04.2023.
//

#ifndef UNTITLED_ANTYLOPA_H
#define UNTITLED_ANTYLOPA_H


#include "Animal.h"

class Antylopa : public Animal{
public:
    Antylopa(World *currentWorld, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
};


#endif //UNTITLED_ANTYLOPA_H

//
// Created by szymo on 08.04.2023.
//

#ifndef UNTITLED_OWCA_H
#define UNTITLED_OWCA_H
#include "Animal.h"


class Owca :public Animal{
public:
    Owca(World *currentWorld, int positionX, int positionY, int age);
    Owca(World *currentWorld, int initative, int strength, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
    Organism * clone()override;
};


#endif //UNTITLED_OWCA_H

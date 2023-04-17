//
// Created by szymo on 07.04.2023.
//

#ifndef UNTITLED_CZLOWIEK_H
#define UNTITLED_CZLOWIEK_H


#include "Animal.h"


class Czlowiek : public Animal{
public:
    Czlowiek(World *currentWorld, int positionX, int positionY, int age);
    Czlowiek(World *currentWorld, int initative, int strength, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
    Organism * clone()override{ return nullptr; };
};


#endif //UNTITLED_CZLOWIEK_H

//
// Created by szymo on 07.04.2023.
//

#ifndef UNTITLED_CZLOWIEK_H
#define UNTITLED_CZLOWIEK_H


#include "Animal.h"

class Czlowiek : public Animal{
public:
    Czlowiek(World *currentWorld, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
};


#endif //UNTITLED_CZLOWIEK_H
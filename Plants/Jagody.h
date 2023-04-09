//
// Created by szymo on 08.04.2023.
//

#ifndef UNTITLED_JAGODY_H
#define UNTITLED_JAGODY_H
#include "Plant.h"


class Jagody : public Plant{
public:
    Jagody(World *currentWorld, int positionX, int positionY);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
};


#endif //UNTITLED_JAGODY_H

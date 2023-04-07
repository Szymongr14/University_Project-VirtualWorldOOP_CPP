//
// Created by szymo on 07.04.2023.
//

#ifndef UNTITLED_MLECZ_H
#define UNTITLED_MLECZ_H
#include "Plant.h"

class Mlecz : public Plant{
public:
    Mlecz(World *currentWorld, int positionX, int positionY);
    void Action() override;
    void Collision(Organism *otherOrganism) override;

};


#endif //UNTITLED_MLECZ_H

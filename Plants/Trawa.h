//
// Created by szymo on 07.04.2023.
//

#ifndef UNTITLED_TRAWA_H
#define UNTITLED_TRAWA_H
#include "Plant.h"


class Trawa : public Plant {
public:
    Trawa(World *currentWorld, int positionX, int positionY);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
};


#endif //UNTITLED_TRAWA_H

//
// Created by szymo on 08.04.2023.
//

#ifndef UNTITLED_BARSZCZ_H
#define UNTITLED_BARSZCZ_H
#include "Plant.h"

class Barszcz : public Plant{
public:
    Barszcz(World *currentWorld, int positionX, int positionY);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
};


#endif //UNTITLED_BARSZCZ_H

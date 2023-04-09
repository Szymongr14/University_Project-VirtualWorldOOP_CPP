//
// Created by szymo on 08.04.2023.
//

#ifndef UNTITLED_GUARANA_H
#define UNTITLED_GUARANA_H
#include "Plant.h"


class Guarana : public Plant{
public:
    Guarana(World *currentWorld, int positionX, int positionY);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
};


#endif //UNTITLED_GUARANA_H

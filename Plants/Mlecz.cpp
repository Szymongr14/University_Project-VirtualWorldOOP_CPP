//
// Created by szymo on 07.04.2023.
//

#include "Mlecz.h"

Mlecz::Mlecz(World *currentWorld, int positionX, int positionY)
    : Plant(currentWorld, positionX, positionY) {
    skin = MLECZ_SKIN;
}

void Mlecz::Action() {
    Plant::Action();
}

void Mlecz::Collision(Organism *otherOrganism) {
    Plant::Collision(otherOrganism);
}

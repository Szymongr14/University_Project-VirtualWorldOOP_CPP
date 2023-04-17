//
// Created by szymo on 07.04.2023.
//

#include "Mlecz.h"

Mlecz::Mlecz(World *currentWorld, int positionX, int positionY)
    : Plant(currentWorld, positionX, positionY,MLECZ_STRENGTH) {
    skin = MLECZ_SKIN;
    name = MLECZ_NAME;
    name_without_color = MLECZ_NORMAL_NAME;
}

void Mlecz::Action() {
    for(int i = 0; i < 3; i++)
        Plant::Action();
}

void Mlecz::Collision(Organism *otherOrganism) {
    Plant::Collision(otherOrganism);
}

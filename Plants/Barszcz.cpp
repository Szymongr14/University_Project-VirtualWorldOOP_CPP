//
// Created by szymo on 08.04.2023.
//

#include "Barszcz.h"

Barszcz::Barszcz(World *currentWorld, int positionX, int positionY)
    : Plant(currentWorld, positionX, positionY,BARSZCZ_STRENGTH) {
    skin = BARSZCZ_SKIN;
    name = BARSZCZ_NAME;
}

void Barszcz::Action() {
    Plant::Action();
}

void Barszcz::Collision(Organism *otherOrganism) {
    Plant::Collision(otherOrganism);
}

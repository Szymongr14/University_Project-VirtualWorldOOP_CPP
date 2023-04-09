//
// Created by szymo on 08.04.2023.
//

#include "Jagody.h"

Jagody::Jagody(World *currentWorld, int positionX, int positionY)
    : Plant(currentWorld, positionX, positionY,JAGODY_STRENGTH) {
    skin = JAGODY_SKIN;
    name = JAGODY_NAME;
}

void Jagody::Action() {
    Plant::Action();
}

void Jagody::Collision(Organism *otherOrganism) {
    Plant::Collision(otherOrganism);
}

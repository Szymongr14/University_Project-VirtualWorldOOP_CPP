//
// Created by szymo on 07.04.2023.
//

#include "Trawa.h"


Trawa::Trawa(World *currentWorld, int positionX, int positionY)
    : Plant(currentWorld, positionX, positionY,TRAWA_STRENGTH) {
    skin = TRAWA_SKIN;
    name = TRAWA_NAME;
    name_without_color = TRAWA_NORMAL_NAME;
}

void Trawa::Action() {
    Plant::Action();
}



void Trawa::Collision(Organism *otherOrganism) {
    Plant::Collision(otherOrganism);
}


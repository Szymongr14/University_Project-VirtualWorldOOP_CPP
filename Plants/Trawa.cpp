//
// Created by szymo on 07.04.2023.
//

#include "Trawa.h"


Trawa::Trawa(World *currentWorld, int positionX, int positionY)
    : Plant(currentWorld, positionX, positionY) {
    skin = TRAWA_SKIN;
}

void Trawa::Action() {
    Plant::Action();

}

void Trawa::Collision(Organism *otherOrganism) {
    Plant::Collision(otherOrganism);
}


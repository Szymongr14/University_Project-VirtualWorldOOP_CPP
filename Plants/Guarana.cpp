//
// Created by szymo on 08.04.2023.
//

#include "Guarana.h"

Guarana::Guarana(World *currentWorld, int positionX, int positionY)
    : Plant(currentWorld, positionX, positionY,BARSZCZ_STRENGTH) {
    skin = GUARANA_SKIN;
    name = GUARANA_NAME;
}

void Guarana::Action() {
    Plant::Action();
}

void Guarana::Collision(Organism *otherOrganism) {
    Plant::Collision(otherOrganism);
}

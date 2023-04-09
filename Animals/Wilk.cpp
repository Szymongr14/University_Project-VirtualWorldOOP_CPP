//
// Created by szymo on 08.04.2023.
//

#include "Wilk.h"

Wilk::Wilk(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, WILK_STRENGTH, WILK_INITIATIVE, positionX, positionY, age) {
    skin = WILK_SKIN;
    name = WILK_NAME;
}

void Wilk::Action() {
    Animal::Action();
}

void Wilk::Collision(Organism *otherOrganism) {
    Animal::Collision(otherOrganism);
}
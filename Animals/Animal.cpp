//
// Created by szymo on 07.04.2023.
//

#include "Animal.h"


void Animal::Action() {

}

void Animal::Collision(Organism *otherOrganism) {

}

Animal::Animal(World *currentWorld, int strength, int initiative, int positionX, int positionY, int age)
    : Organism(currentWorld, strength, initiative, positionX, positionY, age) {

}

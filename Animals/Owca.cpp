//
// Created by szymo on 08.04.2023.
//

#include "Owca.h"

Owca::Owca(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, OWCA_STRENGTH, OWCA_INITIATIVE, positionX, positionY, age) {
    skin = OWCA_SKIN;
    name = OWCA_NAME;
    name_without_color = OWCA_NORMAL_NAME;
}

void Owca::Action() {
    Animal::Action();
}

void Owca::Collision(Organism *otherOrganism) {
    Animal::Collision(otherOrganism);
}

Organism *Owca::clone() {
    return new Owca(currentWorld, this->getX(), this->getY(), 1);
}

Owca::Owca(World *currentWorld, int initative, int strength, int positionX, int positionY, int age)
    : Animal(currentWorld, strength, initative, positionX, positionY, age) {
    skin = OWCA_SKIN;
    name = OWCA_NAME;
    name_without_color = OWCA_NORMAL_NAME;

}



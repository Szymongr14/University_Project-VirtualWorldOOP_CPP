//
// Created by szymo on 08.04.2023.
//

#include "Owca.h"

Owca::Owca(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, OWCA_STRENGTH, OWCA_INITIATIVE, positionX, positionY, age) {
    skin = OWCA_SKIN;
    name = OWCA_NAME;
}

void Owca::Action() {
    Animal::Action();
}

void Owca::Collision(Organism *otherOrganism) {
    if(otherOrganism->getName()==OWCA_NAME){
        Animal *newAnimal = new Owca(currentWorld, this->getX(), this->getY(), 1);
        this->CollisionWithTheSameSpecies(newAnimal);
    }
    else
        Animal::Collision(otherOrganism);
}
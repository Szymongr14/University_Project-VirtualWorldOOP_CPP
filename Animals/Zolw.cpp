//
// Created by szymo on 08.04.2023.
//

#include "Zolw.h"

Zolw::Zolw(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, ZOLW_STRENGTH, ZOLW_INITIATIVE, positionX, positionY, age) {
    skin = ZOLW_SKIN;
    name = ZOLW_NAME;
    name_without_color = ZOLW_NORMAL_NAME;
}

Zolw::Zolw(World *currentWorld, int initative, int strength, int positionX, int positionY, int age)
    : Animal(currentWorld, strength, initative, positionX, positionY, age) {
    skin = ZOLW_SKIN;
    name = ZOLW_NAME;
    name_without_color = ZOLW_NORMAL_NAME;
}

void Zolw::Action() {
    if(rand() % 4 == 0) {
        Animal::Action();
    }
}

void Zolw::Collision(Organism *otherOrganism) {

    if(typeid(*this) == typeid(*otherOrganism)){
        Organism *newAnimal = this->clone();
        this->CollisionWithTheSameSpecies(newAnimal);
        return;
    }
    else if(otherOrganism->getStrength() < this->getStrength()) {
        std::cout<<"Zwierze: "<<this->getName()<<" zjadlo: "<<otherOrganism->getName()<<std::endl;
        otherOrganism->setIsAlive(false);
        currentWorld->removeOrganism(otherOrganism);
        if(otherOrganism->getName() == CZLOWIEK_NAME){
            currentWorld->setGameStatus(false);
        }
    }
    else {
        if(otherOrganism->getStrength()>=5) {
            std::cout << "Zwierze: " << this->getName() << " zostalo zjedzone przez: " << otherOrganism->getName()<< std::endl;
            this->currentWorld->moveOrganism(otherOrganism, this->getX(), this->getY());
            this->setIsAlive(false);
        }
        else
            std::cout<<"Zwierze: "<<this->getName()<<" odparl atak: "<<otherOrganism->getName()<<std::endl;
    }
}

Organism *Zolw::clone() {
    return new Zolw(currentWorld, this->getX(), this->getY(), 1);
}

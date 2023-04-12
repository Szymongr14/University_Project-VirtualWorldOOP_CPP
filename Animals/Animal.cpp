//
// Created by szymo on 07.04.2023.
//

#include "Animal.h"


void Animal::Action() {
    int tempPosition[2] = {position[0], position[1]};
    int tempDirection = rand()%4;
    switch(tempDirection){
        case 0:
            tempPosition[0] += 1;
            break;
        case 1:
            tempPosition[0] -= 1;
            break;
        case 2:
            tempPosition[1] += 1;
            break;
        case 3:
            tempPosition[1] -= 1;
            break;
    }
    if(currentWorld->isPositionValid(tempPosition[0], tempPosition[1])){
        if(currentWorld->getOrganism(tempPosition[0],tempPosition[1]) != nullptr) {
                currentWorld->getOrganism(tempPosition[0],tempPosition[1])->Collision(this);
        }
        else {
            std::cout<<"Ruch zwierzecia: "<<this->getName() << std::endl;
            currentWorld->moveOrganism(this, tempPosition[0], tempPosition[1]);
        }
    }
}

void Animal::Collision(Organism *otherOrganism) {
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
        std::cout<<"Zwierze: "<<this->getName()<<" zostalo zjedzone przez: "<<otherOrganism->getName()<<std::endl;
        this->currentWorld->moveOrganism(otherOrganism, this->getX(), this->getY());
        this->setIsAlive(false);
        if(this->getName() == CZLOWIEK_NAME){
            currentWorld->setGameStatus(false);
        }
    }
}

Animal::Animal(World *currentWorld, int strength, int initiative, int positionX, int positionY, int age)
    : Organism(currentWorld, strength, initiative, positionX, positionY, age) {
}

void Animal::CollisionWithTheSameSpecies(Organism *organismToCreate) {
    std::cout<<"Powstal nowy/a: "<<this->getName()<<std::endl;
    int position = this->currentWorld->returnEmptyPositionAround(this->getX(), this->getY());
    switch(position) {
        case 1:
            organismToCreate->setX(this->getX() + 1);
            organismToCreate->setY(this->getY());
            this->currentWorld->addOrganism(organismToCreate, this->getX() + 1, this->getY());
            break;
        case 2:
            organismToCreate->setX(this->getX() - 1);
            organismToCreate->setY(this->getY());
            this->currentWorld->addOrganism(organismToCreate, this->getX() - 1, this->getY());
            break;
        case 3:
            organismToCreate->setX(this->getX());
            organismToCreate->setY(this->getY() + 1);
            this->currentWorld->addOrganism(organismToCreate, this->getX(), this->getY() + 1);
            break;
        case 4:
            organismToCreate->setX(this->getX());
            organismToCreate->setY(this->getY() - 1);
            this->currentWorld->addOrganism(organismToCreate, this->getX(), this->getY() - 1);
            break;
        case 5:
            std::cout << "Mlody/a: " << this->getName() << " nie przetrwal/a :(" << std::endl;
            delete organismToCreate;
            break;
    }
}

//
// Created by szymo on 08.04.2023.
//

#include "Lis.h"

Lis::Lis(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, LIS_STRENGTH, LIS_INITIATIVE, positionX, positionY, age) {
    skin = LIS_SKIN;
    name = LIS_NAME;
}

void Lis::Action() {
    int direction = rand() % 4;
    int tempPosition[2] = {position[0], position[1]};
    switch (direction) {
        case 0:
            tempPosition[1]--;
            break;
        case 1:
            tempPosition[1]++;
            break;
        case 2:
            tempPosition[0]--;
            break;
        case 3:
            tempPosition[0]++;
            break;
    }

    if(currentWorld->isPositionEmptyAndValid(tempPosition[0],tempPosition[1])) {
        if(currentWorld->getOrganism(tempPosition[0],tempPosition[1]) != nullptr) {
            if(currentWorld->getOrganism(position[1],position[0])->getStrength() < this->getStrength()) {
                currentWorld->getOrganism(position[1],position[0])->Collision(this);
            }
        }
        else {
            std::cout<<"Ruch zwierzecia: "<<this->getName() << std::endl;
            currentWorld->moveOrganism(this, tempPosition[0], tempPosition[1]);
        }
    }
}

void Lis::Collision(Organism *otherOrganism) {
    if(otherOrganism->getName()==LIS_NAME){
        Animal *newAnimal = new Lis(currentWorld, this->getX(), this->getY(), 1);
        this->CollisionWithTheSameSpecies(newAnimal);
    }
    else
        Animal::Collision(otherOrganism);
}

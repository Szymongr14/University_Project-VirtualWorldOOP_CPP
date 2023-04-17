//
// Created by szymo on 07.04.2023.
//

#include "Antylopa.h"


Antylopa::Antylopa(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, ANTYLOPA_STRENGTH, ANTYLOPA_INITIATIVE, positionX, positionY, age) {
    skin = ANTYLOPA_SKIN;
    name = ANTYLOPA_NAME;
    name_without_color = ANTYLOPA_NORMAL_NAME;
}

void Antylopa::Action() {
    int tempPosition[2] = {position[0], position[1]};
    int move = rand() % 8;
    //antylopa can move 2 fields
    switch (move) {
        case 0:
            if(position[1] > 1) {
                tempPosition[1] -= 2;
            }
            break;
        case 1:
            if(position[1] < currentWorld->getHeight() - 2) {
                tempPosition[1] += 2;
            }
            break;
        case 2:
            if(position[0] > 1) {
                tempPosition[0] -= 2;
            }
            break;
        case 3:
            if(position[0] < currentWorld->getWidth() - 2) {
                tempPosition[0] += 2;
            }
            break;
        case 4:
            if(position[1] > 0 && position[0] > 0) {
                tempPosition[1]--;
                tempPosition[0]--;
            }
            break;
        case 5:
            if(position[1] > 0 && position[0] < currentWorld->getWidth() - 1) {
                tempPosition[1]--;
                tempPosition[0]++;
            }
            break;
        case 6:
            if(position[1] < currentWorld->getHeight() - 1 && position[0] > 0) {
                tempPosition[1]++;
                tempPosition[0]--;
            }
            break;
        case 7:
            if(position[1] < currentWorld->getHeight() - 1 && position[0] < currentWorld->getWidth() - 1) {
                tempPosition[1]++;
                tempPosition[0]++;
            }
            break;
    }

    if(tempPosition[0] != position[0] || tempPosition[1] != position[1]) {
        if(currentWorld->getOrganism(tempPosition[0],tempPosition[1]) != nullptr) {
            currentWorld->getOrganism(tempPosition[0],tempPosition[1])->Collision(this);
        }
        else {
            currentWorld->moveOrganism(this, tempPosition[0], tempPosition[1]);
        }
    }
}


void Antylopa::Collision(Organism *otherOrganism) {
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
        if(rand() % 2 == 0) {
            std::cout << "Zwierze: " << this->getName() << " zostalo zjedzone przez: " << otherOrganism->getName()<< std::endl;
            currentWorld->moveOrganism(otherOrganism, this->getX(), this->getY());
            this->setIsAlive(false);
        }
        else{
            std::cout << "Zwierze: " << this->getName() << " ucieklo przed: " << otherOrganism->getName()<< std::endl;
            currentWorld->moveOrganism(otherOrganism, this->getX(), this->getY());
            int position = this->currentWorld->returnEmptyPositionAround(this->getX(), this->getY());
            switch(position){
                case 1:
                    this->currentWorld->escapeToPosition(this, this->getX()+1, this->getY());
                    break;
                case 2:
                    this->currentWorld->escapeToPosition(this, this->getX(), this->getY()-1);
                    break;
                case 3:
                    this->currentWorld->escapeToPosition(this, this->getX(), this->getY()+1);
                    break;
                case 4:
                    this->currentWorld->escapeToPosition(this, this->getX(), this->getY()-1);
                    break;
                case 5:
                    std::cout << "Zwierze: " << otherOrganism->getName() << " dopadlo: " << this->getName()<< std::endl;
                    this->setIsAlive(false);
                    break;
            }
        }
    }
}

Organism *Antylopa::clone() {
    return new Antylopa(currentWorld, this->getX(), this->getY(), 1);
}

Antylopa::Antylopa(World *currentWorld, int initative, int strength, int positionX, int positionY, int age)
    : Animal(currentWorld, strength, initative, positionX, positionY, age) {
    skin = ANTYLOPA_SKIN;
    name = ANTYLOPA_NAME;
    name_without_color = ANTYLOPA_NORMAL_NAME;
}


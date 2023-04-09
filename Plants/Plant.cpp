//
// Created by szymo on 07.04.2023.
//

#include "Plant.h"
#include "Barszcz.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Jagody.h"
#include "Mlecz.h"

void Plant::Action() {
//prawdopodobienstwo rozprzesztrzenienia wynosi 10%
    if(rand()%100 < 10){
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
        if(currentWorld->isPositionEmptyAndValid(tempPosition[0], tempPosition[1])) {
            std::cout << "Zasiano rosline: " << this->getName() << std::endl;
            if (this->getName() == TRAWA_NAME) {
                auto *newPlant = new Trawa(currentWorld, tempPosition[0], tempPosition[1]);
                currentWorld->addOrganism(newPlant, tempPosition[0], tempPosition[1]);
            }else if (this->getName() == MLECZ_NAME) {
                auto *newPlant = new Mlecz(currentWorld, tempPosition[0], tempPosition[1]);
                currentWorld->addOrganism(newPlant, tempPosition[0], tempPosition[1]);
            }else if (this->getName() == GUARANA_NAME) {
                auto *newPlant = new Guarana(currentWorld, tempPosition[0], tempPosition[1]);
                currentWorld->addOrganism(newPlant, tempPosition[0], tempPosition[1]);
            }else if (this->getName() == JAGODY_NAME) {
                auto *newPlant = new Jagody(currentWorld, tempPosition[0], tempPosition[1]);
                currentWorld->addOrganism(newPlant, tempPosition[0], tempPosition[1]);
            }
            else if (this->getName() == BARSZCZ_NAME) {
                auto *newPlant = new Barszcz(currentWorld, tempPosition[0], tempPosition[1]);
                currentWorld->addOrganism(newPlant, tempPosition[0], tempPosition[1]);
            }
        }
    }
}

void Plant::Collision(Organism *otherOrganism) {
    if(otherOrganism->getStrength() < this->getStrength()) {
        std::cout<<"Roslina: "<<this->getName()<<" zabila: "<<otherOrganism->getName()<<std::endl;
        otherOrganism->setIsAlive(false);
        currentWorld->removeOrganism(otherOrganism);
        if(otherOrganism->getName() == CZLOWIEK_NAME){
            currentWorld->setGameStatus(false);
        }
    }
    else {
        std::cout<<"Roslina: "<<this->getName()<<" zostala zjedzone przez: "<<otherOrganism->getName()<<std::endl;

        this->currentWorld->moveOrganism(otherOrganism, this->getX(), this->getY());
//        this->currentWorld->Organisms[this->getY()][this->getX()] = otherOrganism;
//        this->currentWorld->Organisms[otherOrganism->getY()][otherOrganism->getX()] = nullptr;
//        otherOrganism->setX(this->getX());
//        otherOrganism->setY(this->getY());
        this->setIsAlive(false);
        if(this->getName() == CZLOWIEK_NAME){
            currentWorld->setGameStatus(false);
        }
    }
}

Plant::Plant(World *currentWorld, int positionX, int positionY, int strength)
    : Organism(currentWorld,strength,0, positionX, positionY,1){

}




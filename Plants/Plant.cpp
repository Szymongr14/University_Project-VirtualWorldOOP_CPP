//
// Created by szymo on 07.04.2023.
//

#include "Plant.h"

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
        if(currentWorld->isPositionEmptyAndValid(tempPosition[0], tempPosition[1])){
            auto * newPlant = new Plant(currentWorld, tempPosition[0], tempPosition[1], this);
            currentWorld->addOrganism(newPlant->newOrganism, tempPosition[0], tempPosition[1]);
        }
    }
}

void Plant::Collision(Organism *otherOrganism) {

}

Plant::Plant(World *currentWorld, int positionX, int positionY)
    : Organism(currentWorld,0,0, positionX, positionY,1){

}

Plant::Plant(World *currentWorld, int positionX, int positionY, Plant *newOrganism)
    : Organism(currentWorld,0,0, positionX, positionY,1){
    this->newOrganism = newOrganism;
}



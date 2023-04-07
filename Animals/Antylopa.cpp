//
// Created by szymo on 07.04.2023.
//

#include "Antylopa.h"


Antylopa::Antylopa(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, ANTYLOPA_STRENGTH, ANTYLOPA_INITIATIVE, positionX, positionY, age) {
    skin = ANTYLOPA_SKIN;
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
        if(currentWorld->Organisms[tempPosition[1]][tempPosition[0]] != nullptr) {
            currentWorld->Organisms[tempPosition[1]][tempPosition[0]]->Collision(this);
        }
        else {
            currentWorld->Organisms[position[1]][position[0]] = nullptr;
            position[0] = tempPosition[0];
            position[1] = tempPosition[1];
            currentWorld->Organisms[position[1]][position[0]] = this;
        }
    }

}

void Antylopa::Collision(Organism *otherOrganism) {

}



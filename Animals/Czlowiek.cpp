#include "Czlowiek.h"

Czlowiek::Czlowiek(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, CZLOWIEK_STRENGTH, CZLOWIEK_INITIATIVE, positionX, positionY, age) {
    skin = CZLOWIEK_SKIN;
}

void Czlowiek::Action() {
    std::cout<< "Podaj ruch czlowieka: ";
    char move;
    std::cin >> move;
    int tempPosition[2] = {position[0], position[1]};
    switch (move) {
        case 'w':
            if(currentWorld->isPositionEmptyAndValid(position[0], position[1] - 1)) {
                tempPosition[1]--;
            }
            break;
        case 's':
            if(currentWorld->isPositionEmptyAndValid(position[0], position[1] + 1)){
                tempPosition[1]++;
            }
            break;
        case 'a':
            if(currentWorld->isPositionEmptyAndValid(position[0] - 1, position[1])) {
                tempPosition[0]--;
            }
            break;
        case 'd':
            if(currentWorld->isPositionEmptyAndValid(position[0] + 1, position[1])) {
                tempPosition[0]++;
            }
            break;
        default:
            std::cout<< "Niepoprawny ruch" << std::endl;
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

void Czlowiek::Collision(Organism *otherOrganism) {
    Animal::Collision(otherOrganism);
}

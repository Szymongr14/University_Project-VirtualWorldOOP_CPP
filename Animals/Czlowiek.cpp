#include "Czlowiek.h"

Czlowiek::Czlowiek(World *currentWorld, int positionX, int positionY, int age)
    : Animal(currentWorld, CZLOWIEK_STRENGTH, CZLOWIEK_INITIATIVE, positionX, positionY, age) {
    skin = CZLOWIEK_SKIN;
    name = CZLOWIEK_NAME;
    name_without_color = CZLOWIEK_NORMAL_NAME;
}

void Czlowiek::Action() {
    if(this->currentWorld->getCooldown() > 0){
        this->currentWorld->setCooldown(this->currentWorld->getCooldown() - 1);
    }
    if(this->currentWorld->getHumanAbilityTime() > 0){
        std::cout<<std::endl<< "\033[1;35mSpecjalna umiejetnosc czlowieka aktywna. Pozostalo: "<<this->currentWorld->getHumanAbilityTime()<<" tur\033[0m";
        this->currentWorld->setHumanAbilityTime(this->currentWorld->getHumanAbilityTime() - 1);
        this->setStrength(this->getStrength() -1);
    }
    std::cout<<std::endl<< "Podaj ruch czlowieka (w,s,a,d): ";

    std::string fileName;
    char move;
    std::cin >> move;
    int tempPosition[2] = {this->getX(), this->getY()};
    switch (move) {
        case 'w':
            if(currentWorld->isPositionValid(position[0], position[1] - 1)) {
                tempPosition[1]--;
            }
            else{
                std::cout<<"Niepoprawny ruch - tracisz kolejke"<<std::endl;
                return;
            }
            break;
        case 's':
            if(currentWorld->isPositionValid(position[0], position[1] + 1)){
                tempPosition[1]++;
            }
            else{
                std::cout<<"Niepoprawny ruch - tracisz kolejke"<<std::endl;
                return;
            }
            break;
        case 'a':
            if(currentWorld->isPositionValid(position[0] - 1, position[1])) {
                tempPosition[0]--;
            }
            else{
                std::cout<<"Niepoprawny ruch - tracisz kolejke"<<std::endl;
                return;
            }
            break;
        case 'd':
            if(currentWorld->isPositionValid(position[0] + 1, position[1])) {
                tempPosition[0]++;
            }
            else{
                std::cout<<"Niepoprawny ruch - tracisz kolejke"<<std::endl;
                return;
            }
            break;
        case 'r':
            if(this->currentWorld->getCooldown() == 0) {
                this->currentWorld->setCooldown(10);
                this->strength += 5;
                this->currentWorld->setHumanAbilityTime(5);
            }
            else
                std::cout<<"Przed aktywowaniem specjalnosci musisz odczekac jescze: "<<this->currentWorld->getCooldown()<<std::endl;
            return;
        case 'x':
            std::cout<<"Podaj nazwe pliku do zapisu: ";
            std::cin>>fileName;
            this->currentWorld->saveWorld((char*)fileName.c_str());
            return;
        default:
            std::cout<< "Niepoprawny ruch - tracisz kolejke" << std::endl;
            return;
    }


    if(currentWorld->getOrganism(tempPosition[0],tempPosition[1]) != nullptr) {
        currentWorld->getOrganism(tempPosition[0],tempPosition[1])->Collision(this);
    }
    else {
        currentWorld->moveOrganism(this, tempPosition[0], tempPosition[1]);
    }
}

void Czlowiek::Collision(Organism *otherOrganism) {
    Animal::Collision(otherOrganism);
}

Czlowiek::Czlowiek(World *currentWorld, int initative, int strength, int positionX, int positionY, int age)
: Animal(currentWorld, strength, initative, positionX, positionY, age) {
    skin = CZLOWIEK_SKIN;
    name = CZLOWIEK_NAME;
    name_without_color = CZLOWIEK_NORMAL_NAME;
}

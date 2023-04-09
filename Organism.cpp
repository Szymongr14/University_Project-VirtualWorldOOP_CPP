#include "Organism.h"

Organism::Organism(World *currentWorld, int strength, int initiative, int positionX, int positionY, int age)
    : currentWorld(currentWorld), strength(strength), initiative(initiative), position{positionX, positionY}, age(age) {
}

std::string Organism::draw() const {
    return skin;
}

int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

void Organism::setX(int x) {
    position[0] = x;
}

void Organism::setY(int y) {
    position[1] = y;
}

int Organism::getX() {
    return position[0];
}

int Organism::getY() {
    return position[1];
}

int Organism::getAge() const {
    return age;
}

void Organism::increaseAge() {
    this->age += age;
}

std::string Organism::getName() {
    return name;
}

void Organism::setIsAlive(bool dead) {
    this->isAlive = dead;
}

bool Organism::getIsAlive() const {
    return isAlive;
}

void Organism::setStrength(int strength_value) {
    this->strength = strength_value;
}



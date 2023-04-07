
#ifndef UNTITLED_ANIMAL_H
#define UNTITLED_ANIMAL_H
#include "../Organism.h"

class Animal : public Organism{
public:
    Animal(World *currentWorld, int strength, int initiative, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
};


#endif //UNTITLED_ANIMAL_H

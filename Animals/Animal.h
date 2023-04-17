
#ifndef UNTITLED_ANIMAL_H
#define UNTITLED_ANIMAL_H
#include "../Organism.h"
#include <string>

class Animal : public Organism{
public:
    Animal(World *currentWorld, int strength, int initiative, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
    ~Animal() override = default;
    void CollisionWithTheSameSpecies(Organism *otherOrganism);
    virtual Organism * clone() = 0;


};


#endif //UNTITLED_ANIMAL_H

//
// Created by szymo on 07.04.2023.
//

#ifndef UNTITLED_PLANT_H
#define UNTITLED_PLANT_H
#include "../Organism.h"

class Plant : public Organism{
public:
    Plant(World *currentWorld, int positionX, int positionY, int strength);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
    ~Plant() override = default;
};


#endif //UNTITLED_PLANT_H

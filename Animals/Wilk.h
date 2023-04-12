//
// Created by szymo on 08.04.2023.
//

#ifndef UNTITLED_WILK_H
#define UNTITLED_WILK_H
#include "Animal.h"

class Wilk :public Animal{
public:
    Wilk(World *currentWorld, int positionX, int positionY, int age);
    void Action() override;
    void Collision(Organism *otherOrganism) override;
    Organism *clone()override;
};


#endif //UNTITLED_WILK_H

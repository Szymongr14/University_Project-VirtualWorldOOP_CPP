#ifndef UNTITLED_ORGANISM_H
#define UNTITLED_ORGANISM_H
#include "Settings.h"
#include <ctime>
#include  "World.h"

class Organism {
protected:
    World *currentWorld;                    // Świat w którym się znajduje organizm
    int strength;                           // Siła organizmu
    int initiative;                         // Inicjatywa organizmu
    int position[2];                        // Pozycja X oraz Y
    char skin;                              // Znak reprezentujący organizm na planszy
    int age{};                                // Wiek organizmu, ustalany z góry w konstruktorze
public:
    Organism(World *currentWorld, int strength, int initiative, int positionX, int positionY, int age);

    virtual void Action() = 0;
    virtual void Collision(Organism *otherOrganism) = 0;

    char draw() const;
    int getStrength() const;
    int getInitiative() const;
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    int getAge() const;
    void increaseAge();
    virtual ~Organism() = default;
};


#endif //UNTITLED_ORGANISM_H

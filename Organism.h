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
    std::string skin;                              // Znak reprezentujący organizm na planszy
    std::string name;                       // Nazwa organizmu
    int age{};                                // Wiek organizmu, ustalany z góry w konstruktorze
    bool isAlive = true;                      // Czy organizm żyje
public:
    Organism(World *currentWorld, int strength, int initiative, int positionX, int positionY, int age);

    virtual void Action() = 0;
    virtual void Collision(Organism *otherOrganism) = 0;

    std::string draw() const;
    int getStrength() const;
    void setStrength(int strength_value);
    int getInitiative() const;
    void setX(int x);
    void setY(int y);
    void setIsAlive(bool isAlive);

    bool getIsAlive() const;

    int getX();
    int getY();
    int getAge() const;
    void increaseAge();
    std::string getName();
    virtual ~Organism() = default;
};


#endif //UNTITLED_ORGANISM_H

#ifndef UNTITLED_ORGANISM_H
#define UNTITLED_ORGANISM_H
#include "Settings.h"
#include <ctime>
#include  "World.h"

class Organism {
protected:
    World *currentWorld;
    int strength;
    int initiative;
    int position[2];
    std::string skin;
    std::string name;
    std::string name_without_color;
    int age;
    bool isAlive = true;
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
    const std::string &getNameWithoutColor() const;
    void setNameWithoutColor(const std::string &nameWithoutColor);
    const std::string &getSkin() const;
    void setInitiative(int initiative);
    void setSkin(const std::string &skin);
    void setName(const std::string &name);
    void setAge(int age);
    int getX();
    int getY();
    int getAge() const;
    void increaseAge();
    std::string getName();
    virtual ~Organism() = default;
};


#endif //UNTITLED_ORGANISM_H

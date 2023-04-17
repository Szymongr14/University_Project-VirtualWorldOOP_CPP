#include <algorithm>
#include <fstream>
#include "World.h"
#include "Animals/Czlowiek.h"
#include "Animals/Antylopa.h"
#include "Animals/Lis.h"
#include "Animals/Wilk.h"
#include "Animals/Zolw.h"
#include "Animals/Owca.h"
#include "Plants/Barszcz.h"
#include "Plants/Trawa.h"
#include "Plants/Mlecz.h"
#include "Plants/Jagody.h"
#include "Organism.h"
#include "Plants/Guarana.h"


World::World(int height, int width)
    : height(height), width(width), Organisms(height, std::vector<Organism*>(width, nullptr)), Board(height, std::vector<std::string>(width, "-")) {
    srand(time(nullptr));
    //placing the first human
    placeRandomOnPosition(new Czlowiek(this, -1, -1, 20));
    cooldown = 0;


    //placing first animals
    for(int i = 0; i < 2; i++) {
        placeRandomOnPosition(new Antylopa(this, -1, -1, 7));
        placeRandomOnPosition(new Lis(this, -1, -1, 7));
        placeRandomOnPosition(new Wilk(this, -1, -1, 9));
        placeRandomOnPosition(new Zolw(this, -1, -1, 40));
        placeRandomOnPosition(new Owca(this, -1, -1, 4));
    }



    //placing first plants
    placeRandomOnPosition(new Trawa(this, -1, -1));
    placeRandomOnPosition(new Trawa(this, -1, -1));
    placeRandomOnPosition(new Mlecz(this, -1, -1));
    placeRandomOnPosition(new Guarana(this, -1, -1));
    placeRandomOnPosition(new Barszcz(this, -1, -1));
    placeRandomOnPosition(new Jagody(this, -1, -1));
}

World::World(const char * fileName) {
    srand(time(nullptr));
    std::ifstream worldSave;
    worldSave.open(fileName, std::ios::in);
    std::cout<< "Loading world from file: " << fileName << std::endl;
    worldSave>> this->height;
    worldSave>> this->width;
    worldSave>> this->turn;
    worldSave>> this->cooldown;
    worldSave>> this->humanAbilityTime;

    Organisms.resize(height);
    Board.resize(height);
    for (int i = 0; i < height; i++) {
        Organisms[i].resize(width, nullptr);
        Board[i].resize(width, "-");
    }

    std::string name;
    int strength_val, initiative_val, age_val, positionX_val,positionY_val;


    while (worldSave >> name >> strength_val >> initiative_val >> positionX_val >> positionY_val >> age_val) {
        if(name==CZLOWIEK_NORMAL_NAME){
            placeOnPosition(new Czlowiek(this, strength_val, initiative_val, positionX_val, positionY_val, age_val), positionX_val, positionY_val);
        }
        else if(name==ANTYLOPA_NORMAL_NAME){
            placeOnPosition(new Antylopa(this, strength_val, initiative_val, positionX_val, positionY_val, age_val), positionX_val, positionY_val);
        }
        else if(name==LIS_NORMAL_NAME){
            placeOnPosition(new Lis(this, strength_val, initiative_val, positionX_val, positionY_val, age_val), positionX_val, positionY_val);
        }
        else if(name==WILK_NORMAL_NAME){
            placeOnPosition(new Wilk(this, strength_val, initiative_val, positionX_val, positionY_val, age_val), positionX_val, positionY_val);
        }
        else if(name==ZOLW_NORMAL_NAME){
            placeOnPosition(new Zolw(this, strength_val, initiative_val, positionX_val, positionY_val, age_val), positionX_val, positionY_val);
        }
        else if(name==OWCA_NORMAL_NAME){
            placeOnPosition(new Owca(this, strength_val, initiative_val, positionX_val, positionY_val, age_val), positionX_val, positionY_val);
        }
        else if(name==TRAWA_NORMAL_NAME){
            placeOnPosition(new Trawa(this,positionX_val, positionY_val), positionX_val, positionY_val);
        }
        else if(name==MLECZ_NORMAL_NAME){
            placeOnPosition(new Mlecz(this,positionX_val, positionY_val), positionX_val, positionY_val);
        }
        else if(name==GUARANA_NORMAL_NAME){
            placeOnPosition(new Guarana(this, positionX_val, positionY_val), positionX_val, positionY_val);
        }
        else if(name==BARSZCZ_NORMAL_NAME){
            placeOnPosition(new Barszcz(this,positionX_val, positionY_val), positionX_val, positionY_val);
        }
    }

    worldSave.close();
    updateBoard();
}


void World::saveWorld(const char *fileName) {
    std::ofstream worldSave;
    worldSave.open(fileName, std::ios::out);
    std::cout<< "Saving world to file: " << fileName << std::endl;

    worldSave<<this->height<<std::endl;
    worldSave<<this->width<<std::endl;
    worldSave<<this->turn<<std::endl;
    worldSave<<this->cooldown<<std::endl;
    worldSave<<this->humanAbilityTime<<std::endl;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(Organisms[i][j] != nullptr) {
                worldSave<<Organisms[i][j]->getNameWithoutColor()<<" "<<Organisms[i][j]->getStrength()<<" "<<Organisms[i][j]->getInitiative()<<" "<<Organisms[i][j]->getX()<<" "<<Organisms[i][j]->getY()<<" "<<Organisms[i][j]->getAge()<<std::endl;
            }
        }
    }

    std::cout<< "Game has been successfully saved to file:  " << fileName << std::endl;
    worldSave.close();
}


bool World::getGameStatus() const {
    return game_status;
}

bool World::isPositionEmptyAndValid(int x, int y) {
    if(x < 0 || x >= width || y < 0 || y >= height) {
        return false;
    }
    return this->Organisms[y][x] == nullptr;
}

void World::drawWorld() {
    //displaying legend of the board
    std::cout << "                                   \033[35mLegenda\033[0m: " << std::endl;
    std::cout << "[C - Czlowiek] , [A - Antylopa], [L - Lis], [W - Wilk], [Z- Zolw], [O - Owca] " << std::endl;
    std::cout<< "[T - Trawa], [M - Mlecz], [G - Guarana], [B - Barszcz Sosnowskiego], [J - Jagody]" << std::endl;
    std::cout<<std::endl<< "          \033[35mSterowanie\033[0m: (w,s,a,d)      \033[35mAktywacja specjalnej umiejetnosci\033[0m: r" << std::endl;
    std::cout<<std::endl;
    std::cout << "Tura: " << this->turn<<std::endl;
    //displaying the board
    for(int i = 0; i < width+1; i++)
        std::cout << "#"<<" ";
    std::cout << std::endl;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(j == 0)
                std::cout << "#";
            std::cout << this->Board[i][j] << " ";
            if(j == width-1)
                std::cout << "#";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < width+1; i++)
        std::cout << "#"<<" ";
    std::cout << std::endl;
}

void World::placeRandomOnPosition(Organism *organism) {

    int x = rand() % width;
    int y = rand() % height;
    while(this->Organisms[y][x] != nullptr) {
        x = rand() % width;
        y = rand() % height;
    }
    this->addOrganism(organism, x, y);
}

bool compareOrganisms(Organism* organism1, Organism* organism2) {
    if(organism1->getInitiative() == organism2->getInitiative())
        return organism1->getAge() > organism2->getAge();
    return organism1->getInitiative() > organism2->getInitiative();
}

void World::makeTurn() {
    // Get all organisms
    std::vector<Organism*> organisms;
    std::vector<Organism*> toBeDeleted;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(this->Organisms[i][j] != nullptr) {
                organisms.push_back(this->Organisms[i][j]);
            }
        }
    }
    //updating organisms' age
    for(auto & organism : organisms) {
        organism->increaseAge();
    }
    // Sort organisms by initiative
    std::sort(organisms.begin(), organisms.end(), compareOrganisms);

    // Making a turn
    for(auto & organism : organisms) {
        if(organism->getIsAlive())
            organism->Action();
        else {
            toBeDeleted.push_back(organism);
        }
    }


    for(auto & organism : toBeDeleted) {
        delete organism;
    }
    this->turn++;

    organisms.clear();
    toBeDeleted.clear();

   updateBoard();

}


int World::getHeight() const {
    return height;
}

int World::getWidth() const {
    return width;
}

void World::addOrganism(Organism *organism, int x, int y) {
    this->Organisms[y][x] = organism;
    this->Board[y][x] = organism->draw();
    organism->setX(x);
    organism->setY(y);
}

void World::setGameStatus(bool status) {
    this->game_status = status;
}

void World::setCooldown(int cooldown) {
    this->cooldown = cooldown;
}

int World::getCooldown() const {
    return this->cooldown;
}

int World::getTurn() const {
    return this->turn;
}

bool World::isPositionValid(int x, int y) const {
    if(x < 0 || x >= width || y < 0 || y >= height) {
        return false;
    }
    return true;
}

void World::removeOrganism(Organism *organism) {
    this->Organisms[organism->getY()][organism->getX()] = nullptr;
}

int World::returnEmptyPositionAround(int x, int y){
    if(isPositionEmptyAndValid(x+1,y) && this->Organisms[y][x+1] == nullptr)
        return 1;
    if(isPositionEmptyAndValid(x-1,y) && this->Organisms[y][x-1] == nullptr)
        return 2;
    if(isPositionEmptyAndValid(x,y+1) && this->Organisms[y+1][x] == nullptr)
        return 3;
    if(isPositionEmptyAndValid(x,y-1) && this->Organisms[y-1][x] == nullptr)
        return 4;
    return 5;
}

void World::moveOrganism(Organism *organism, int x, int y) {
    this->Organisms[organism->getY()][organism->getX()] = nullptr;
    this->Organisms[y][x] = organism;
    organism->setX(x);
    organism->setY(y);
}

void World::escapeToPosition(Organism *organism, int x, int y) {
    this->Organisms[y][x] = organism;
    organism->setX(x);
    organism->setY(y);
}

Organism *World::getOrganism(int x, int y) {
    return this->Organisms[y][x];
}

int World::getHumanAbilityTime() const {
    return humanAbilityTime;
}

void World::setHumanAbilityTime(int humanAbilityTime) {
    World::humanAbilityTime = humanAbilityTime;
}

void World::placeOnPosition(Organism *organism, int x, int y) {
    this->Organisms[y][x] = organism;
    organism->setX(x);
    organism->setY(y);
}

void World::updateBoard() {
    // Update Board with Organisms
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(this->Organisms[i][j] != nullptr) {
                this->Board[i][j] = this->Organisms[i][j]->draw();
            }
            else
                this->Board[i][j] = '-';
        }
    }
}





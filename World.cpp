#include <algorithm>
#include "World.h"
#include "Animals/Czlowiek.h"
#include "Animals/Antylopa.h"
#include "Plants/Trawa.h"
#include "Plants/Mlecz.h"
#include "Organism.h"



World::World(int height, int width)
    : height(height), width(width), Organisms(height, std::vector<Organism*>(width, nullptr)), Board(height, std::vector<char>(width, '-')) {

    //placing the first human
    placeRandomOnPosition(new Czlowiek(this, -1, -1, 20));
    cooldown = 0;


    //placing first animals
    for(int i = 0; i < 2; i++)
        placeRandomOnPosition(new Antylopa(this, -1, -1, 7));


    //placing first plants
    placeRandomOnPosition(new Trawa(this, -1, -1));
    placeRandomOnPosition(new Mlecz(this, -1, -1));
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
    srand(time(nullptr));
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
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(this->Organisms[i][j] != nullptr) {
                organisms.push_back(this->Organisms[i][j]);
            }
        }
    }
    // Sort organisms by initiative
    std::sort(organisms.begin(), organisms.end(), compareOrganisms);

    // Making a turn
    for(auto & organism : organisms) {
        organism->Action();
    }
    this->turn++;

    //updating organisms' age
    for(auto & organism : organisms) {
        organism->increaseAge();
    }

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

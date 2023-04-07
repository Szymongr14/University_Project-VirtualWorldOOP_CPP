#include <iostream>
#include "World.h"

using namespace std;

void initalizeNewWorld() {
    int height, width;
    cout<<("Wpisz wysokosc: ");
    cin>>height;
    cout<<("Wpisz szerokosc: ");
    cin>>width;
    system("cls");
    World nowySwiat(height, width);


    while (nowySwiat.getGameStatus()) {
        system("cls");
        nowySwiat.drawWorld();
        nowySwiat.makeTurn();
    }
}




int main() {
    char zn;
    do {

        cout<<("-----------------------------------")<<endl;
        cout<<("|    Szymon Groszkowski 193141    |")<<endl;
        cout<<("|      Sterowanie: strzalki       |")<<endl;
        cout<<("|         Wybierz opcje:          |")<<endl;
        cout<<("|         n - nowa gra            |")<<endl;
        cout<<("|         l - wczytaj gre         |")<<endl;
        cout<<("|            q - wyjdz            |")<<endl;
        cout<<("-----------------------------------")<<endl;
        cout<<endl;
        cout<<"Podaj wybor: ";
        cin>>zn;
        switch (zn) {
            case 'n':
                initalizeNewWorld();
                break;
            case 'l':
                break;
        }
    } while (zn != 'q');

    std::cin.get();
    return 0;
}

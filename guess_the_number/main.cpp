#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

template<typename Map>
    void PrintMap(Map& m) {
        for (auto &item : m) {
            cout << item.first << ":" << item.second << "\n";
        }
    }

int main()
{
    // Welcome string
    cout<<"Welcome To The Guess The Number"<<endl;

    // Settings Map
    map<string, int> settingsMap = {
    {"Start Game", 1,},
    {"Rules", 2,},
    {"Exit", 3,}};

    PrintMap(settingsMap);
    cout<<"\n"<<endl;

    // Settings Selection
    cout<<"Selection of setting: ";
    int s;
    cin>>s;


    switch(s){

    case 3: // Exit
    {
        cout<<"Invalide value. Exitting the game!"<<endl;
        break;
    }

    case 2: // Rules
    {
        cout<<"1. You are playing against the computer.\n2. Your purpose is to guess the random number.\n3. You have 6 life.\n\n"<<endl;

    }

    case 1: // Start Game
    {
        cout<<"start Playing\n"<<endl;
        int  rN; // random number generated by computer.
        srand(time(0));
        rN = rand() % 100;
        int userTN = 0; // user try record

        while (userTN <=6){
            float userI; // user input
            cout<<"Enter your guess: ";
            cin>>userI;

            if (userI < rN) {
                if (userTN == 6) {
                    cout<<"Game over. You loose!"<<endl;
                    break;
                } else {
                    userTN = userTN + 1;
                    cout<<"Try higher!"<<endl;
                }
            } else if (userI == rN) {
                cout<<"Congrugulations you won!";
                break;

            } else {
                if (userTN==6){
                    cout<<"Game over. You loose!"<<endl;
                    break;
                } else {
                    userTN = userTN + 1;
                    cout<<"Try lower!"<<endl;
                }
            }
        }
        break;
    }

    } // End of switch statement.
}

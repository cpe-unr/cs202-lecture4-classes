#include <iostream>
#include <fstream>
#include <string>

const int NUMCATPARAMS = 5;
using namespace std;

// Version 0: (bad) procedural programming
int catSleepTime(int catAge, string catBreed);


int main() {
    ifstream catDataStream;
    catDataStream.open("catdata.txt");
    if(catDataStream.bad()){
        cout << "Could not open file" << endl;
        return 0;
    }
    string catInfo[NUMCATPARAMS];
    int index = 0;
    string tmp;
    for(index = 0; index < NUMCATPARAMS; index++){
        getline(catDataStream, catInfo[index]);
    }
    string catName = catInfo[0];
    string nameCatCallsSelf = catInfo[1];
    int catAge =  stoi(catInfo[2]);
    string catFurColor = catInfo[3];
    string catBreed = catInfo[4];
    cout << "Cat Name: " << catName << "\n";
    cout << "Cat Real Name: " << nameCatCallsSelf << "\n";
    cout << "Cat Fur Color: " << catFurColor << "\n";
    cout << "Cat Breed: " << catBreed << "\n";
    int sleepTime = catSleepTime(catAge, catBreed);
    cout << "Cat Sleep Time: " << sleepTime << "\n";
    return 0;
}

int catSleepTime(int catAge, string catBreed){
    int sleepTime = 0;
    if(catBreed.compare("persion")){
        return catAge > 10 ? 20 : 10;
    };
    return sleepTime;

}

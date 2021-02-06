#include <iostream>
#include <fstream>
#include <string>

const int NUMCATPARAMS = 5;
using namespace std;

// Version 1: (better) procedural programming
int catSleepTime(int catAge, string catBreed);


void printCatDetails(const string &catName, const string &nameCatCallsSelf, int catAge, const string &catFurColor,
                     const string &catBreed);

// ifstream cannot be const!
void getCatInfo(ifstream &catDataStream, string &catName, string &nameCatCallsSelf,
                int &catAge, string &catFurColor,
                string &catBreed, string catInfo[]);

int main() {
    ifstream catDataStream;
    catDataStream.open("catdata.txt");
    if (catDataStream.bad()) {
        cout << "Could not open file" << endl;
        return 0;
    }
    string catName;
    string nameCatCallsSelf;
    int catAge;
    string catFurColor;
    string catBreed;
    string catInfo[NUMCATPARAMS];
    getCatInfo(catDataStream, catName, nameCatCallsSelf, catAge,
               catFurColor, catBreed, catInfo);
    printCatDetails(catName, nameCatCallsSelf, catAge, catFurColor, catBreed);
    return 0;
}

void getCatInfo(ifstream &catDataStream, string &catName, string &nameCatCallsSelf, int &catAge, string &catFurColor,
           string &catBreed, string catInfo[]) {
    int index = 0;
    string tmp;
    for (index = 0; index < NUMCATPARAMS; index++) {
        getline(catDataStream, catInfo[index]);
    }
    catName = catInfo[0];
    nameCatCallsSelf = catInfo[1];
    catAge = stoi(catInfo[2]);
    catFurColor = catInfo[3];
    catBreed = catInfo[4];
}

void printCatDetails(const string &catName, const string &nameCatCallsSelf, int catAge, const string &catFurColor,
                     const string &catBreed) {
    cout << "Cat Name: " << catName << "\n";
    cout << "Cat Real Name: " << nameCatCallsSelf << "\n";
    cout << "Cat Fur Color: " << catFurColor << "\n";
    cout << "Cat Breed: " << catBreed << "\n";
    int sleepTime = catSleepTime(catAge, catBreed);
    cout << "Cat Sleep Time: " << sleepTime << "\n";
}

int catSleepTime(int catAge, string catBreed) {
    int sleepTime = 0;
    if (catBreed.compare("persion")) {
        return catAge > 10 ? 20 : 10;
    };
    return sleepTime;

}

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

// Version 3: Kinda getting there with OO

class Cat {
    static const int NUMCATPARAMS = 5;
    bool catInfoLoaded = false;
    string catName;
    string nameCatCallsSelf;
    int catAge;
    string catFurColor;
    string catBreed;

private:
    void getCatInfo(ifstream &catDataStream) {
        string catInfo[NUMCATPARAMS];
        int index = 0;
        for (index = 0; index < NUMCATPARAMS; index++) {
            getline(catDataStream, catInfo[index]);
        }
        catName = catInfo[0];
        nameCatCallsSelf = catInfo[1];
        catAge = stoi(catInfo[2]);
        catFurColor = catInfo[3];
        catBreed = catInfo[4];
    }
    int catSleepTime() {
        int sleepTime = 0;
        if (catBreed.compare("persion")) {
            return catAge > 10 ? 20 : 10;
        };
        return sleepTime;
    }
public:
    bool init(const string catInfoFile){
        ifstream catDataStream;
        catDataStream.open(catInfoFile);
        if (catDataStream.bad()) {
            cout << "Could not open file" << endl;
            return false;
        }
        getCatInfo(catDataStream);
        catDataStream.close();
        catInfoLoaded = true;
        return true;
    }

    void printCatDetails() {
        cout << "Cat Name: " << catName << "\n";
        cout << "Cat Real Name: " << nameCatCallsSelf << "\n";
        cout << "Cat Fur Color: " << catFurColor << "\n";
        cout << "Cat Breed: " << catBreed << "\n";
        int sleepTime = catSleepTime();
        cout << "Cat Sleep Time: " << sleepTime << "\n";
    }
};

int main() {
    Cat myCat;
    myCat.init("catdata.txt");
    myCat.printCatDetails();
}



#include "cat.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    Cat myCat;
    myCat.init("catdata.txt");
    myCat.printCatDetails();
}



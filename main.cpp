#include <iostream>
#include "Header/Person.h"
#include "Header/FileFinder.h"
using namespace std;

int main() {
    FileFinder directory1("C:/Users/Canel/Desktop");
    cout << "Es gibt soviele Files:" << directory1.countAllFiles() << ". Diese sind bisher in Liste:" << " // ";
    directory1.printAll();
    directory1.pushAllFiles();
    cout << " // " << " Diese sind jetzt nach push in Liste:";
    directory1.printAll();
    return 0;
}

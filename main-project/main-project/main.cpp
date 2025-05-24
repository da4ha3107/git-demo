#include <iostream>
#include <algorithm>
#include "presentation.h"
#include "io.h"
#include <locale>
#include <windows.h>


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    setlocale(LC_ALL, "Russian");
    std::vector<Presentation> presentations = readPresentations("data.txt");

    std::sort(presentations.begin(), presentations.end(), compareByStartTime);

    for (const auto& p : presentations) {
        std::cout << p.timeStart << " - " << p.timeEnd << " | "
            << p.speakerFullName << " | "
            << p.topic << "\n";
    }

    std::string name;
    std::cout << "Vvtite FIO dliy poiska: ";
    

    std::getline(std::cin >> std::ws, name);
    searchBySpeaker(presentations, name);

    return 0;
}



#include <iostream>
#include <algorithm>
#include <vector>
#include <locale>
#include <windows.h>
#include "presentation.h"
#include "io.h"
#include "file_reader.h"
#include "sort.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    std::cout << "Students Group: 24PI1d\n";

    std::vector<Presentation> presentations = readFromFile("data.txt");

    std::sort(presentations.begin(), presentations.end(), compareByStartTime);
    std::cout << "Spisok dokladov:\n-----------------------------\n";
    for (const auto& p : presentations) {
        std::cout << p.timeStart << " - " << p.timeEnd << " | "
            << p.speakerFullName << " | " << p.topic << "\n";
    }

    int sortChoice, compareChoice;
    std::cout << "\nVyberite metod sortirovki:\n0 - Heap sort\n1 - Merge sort\n> ";
    std::cin >> sortChoice;

    std::cout << "Vyberite kriteriy sortirovki:\n0 - Po ubivaniyu dlyitelnosti\n1 - Po FIO i teme\n> ";
    std::cin >> compareChoice;

    std::vector<Presentation*> ptrs(presentations.size());
    for (size_t i = 0; i < presentations.size(); ++i)
        ptrs[i] = &presentations[i];

    SortFunc sortMethods[] = { heapSort, mergeSort };
    CompareFunc compareMethods[] = { compareByDurationDesc, compareByNameAndTopic };

    sortMethods[sortChoice](ptrs.data(), presentations.size(), compareMethods[compareChoice]);

    std::cout << "\nOtsortirovannye dannye:\n-----------------------------\n";
    for (size_t i = 0; i < presentations.size(); ++i)
        std::cout << ptrs[i]->timeStart << " - " << ptrs[i]->timeEnd << " | "
        << ptrs[i]->speakerFullName << " | " << ptrs[i]->topic << "\n";

    // ?? Вставляем выбор фильтра перед поиском ФИО
    int filterChoice;
    std::cout << "\nVyberite filtr:\n1 - Po FIO\n2 - Po dlyitelnosti (>15 min)\n> ";
    std::cin >> filterChoice;

    if (filterChoice == 1) {
        std::string name;
        std::cout << "Vvedite FIO: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        filterBySpeaker(presentations, name);
    }
    else if (filterChoice == 2) {
        filterByDuration(presentations, 15);
    }

    // ?? Оставляем поиск по ФИО после фильтрации
    std::string name;
    std::cout << "\nVvedite FIO dlya poiska: ";
    std::getline(std::cin >> std::ws, name);
    std::vector<Presentation> sortedPresentations;
    for (Presentation* p : ptrs)
        sortedPresentations.push_back(*p);
    searchBySpeaker(sortedPresentations, name);

    return 0;
}

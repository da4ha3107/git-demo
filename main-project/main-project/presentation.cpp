#include "presentation.h"
#include <sstream>
#include <vector>
#include <iostream>

//вычисления длительности доклада
int getDurationInMinutes(const Presentation& p) {
    int h1, m1, h2, m2;
    char colon;
    std::istringstream ss1(p.timeStart), ss2(p.timeEnd);
    ss1 >> h1 >> colon >> m1;
    ss2 >> h2 >> colon >> m2;
    return (h2 * 60 + m2) - (h1 * 60 + m1);
}

// сравнения по времени начала
bool compareByStartTime(const Presentation& a, const Presentation& b) {
    return a.timeStart < b.timeStart;
}

// фильтрации по ФИО докладчика
void filterBySpeaker(const std::vector<Presentation>& presentations, const std::string& speaker) {
    std::cout << "Доклады от " << speaker << ":\n";
    for (const auto& p : presentations) {
        if (p.speakerFullName == speaker) {
            std::cout << p.timeStart << " - " << p.timeEnd << " | " << p.topic << "\n";
        }
    }
}

//фильтрация по длительности доклада (больше `minDuration` минут)
void filterByDuration(const std::vector<Presentation>& presentations, int minDuration) {
    std::cout << "Доклады длительностью больше " << minDuration << " минут:\n";
    for (const auto& p : presentations) {
        if (getDurationInMinutes(p) > minDuration) {
            std::cout << p.timeStart << " - " << p.timeEnd << " | " << p.speakerFullName << " | " << p.topic << "\n";
        }
    }
}

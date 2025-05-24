#include "io.h"
#include <fstream>
#include <iostream>

std::vector<Presentation> readPresentations(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Presentation> presentations;
    Presentation p;

    std::string lastName, firstName, middleName;
    std::string topic1, topic2;

    while (file >> p.timeStart >> p.timeEnd
        >> lastName >> firstName >> middleName
        >> topic1 >> topic2) {
        p.speakerFullName = lastName + " " + firstName + " " + middleName;
        p.topic = topic1 + " " + topic2;

        presentations.push_back(p);
    }

    return presentations;
}

void searchBySpeaker(const std::vector<Presentation>& presentations, const std::string& name) {
    std::cout << "Vistypleniy dliy: " << name << "\n";

    bool found = false;
    for (const auto& p : presentations) {
        if (p.speakerFullName == name) {
            std::cout << p.timeStart << " - " << p.timeEnd << " | "
                << p.topic << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Nichego ne naideno.\n";
    }
}

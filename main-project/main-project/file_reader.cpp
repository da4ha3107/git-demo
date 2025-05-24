#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <vector>

std::vector<Presentation> readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Presentation> result;
    std::string lastName, firstName, middleName, topic1, topic2;
    Presentation p;

    while (file >> p.timeStart >> p.timeEnd >> lastName >> firstName >> middleName >> topic1 >> topic2) {
        p.speakerFullName = lastName + " " + firstName + " " + middleName;
        p.topic = topic1 + " " + topic2;
        result.push_back(p);
    }

    return result;
}

#pragma once
#include <string>

struct Presentation {
    std::string timeStart;
    std::string timeEnd;
    std::string speakerFullName;
    std::string topic;
};
int getDurationInMinutes(const Presentation& p);

bool compareByStartTime(const Presentation& a, const Presentation& b);


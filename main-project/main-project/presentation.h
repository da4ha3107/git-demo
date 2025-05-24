#pragma once
#include <string>

struct Presentation {
    std::string timeStart;
    std::string timeEnd;
    std::string speakerFullName;
    std::string topic;
};

bool compareByStartTime(const Presentation& a, const Presentation& b);


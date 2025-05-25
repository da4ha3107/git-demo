#pragma once
#include <string>
#include <vector>
struct Presentation {
    std::string timeStart;
    std::string timeEnd;
    std::string speakerFullName;
    std::string topic;
};
int getDurationInMinutes(const Presentation& p);

bool compareByStartTime(const Presentation& a, const Presentation& b);

void filterBySpeaker(const std::vector<Presentation>& presentations, const std::string& speaker);
void filterByDuration(const std::vector<Presentation>& presentations, int minDuration);

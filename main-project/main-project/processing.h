#pragma once
#include <vector>
#include <string>

struct Talk {
    std::string title;
    int duration_minutes; // длительность в минутах
};

std::string process(const std::vector<Talk>& talks);


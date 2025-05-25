#pragma once
#include <vector>
#include <string>

struct Talk {
    std::string title;
    int duration_minutes; // ������������ � �������
};

std::string process(const std::vector<Talk>& talks);


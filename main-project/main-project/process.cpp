#include "processing.h"
#include <iomanip>
#include <sstream>

std::string process(const std::vector<Talk>& talks) {
    if (talks.empty()) return "00:00"; // ���� ������ �������� ����, ���������� "00:00"

    int maxDuration = 0;
    for (const auto& talk : talks)
        if (talk.duration_minutes > maxDuration)
            maxDuration = talk.duration_minutes;

    std::ostringstream result;
    result << std::setw(2) << std::setfill('0') << maxDuration / 60 << ":"
        << std::setw(2) << std::setfill('0') << maxDuration % 60;

    return result.str(); // ���������� ����� ������� ������ � ������� ��:��
}

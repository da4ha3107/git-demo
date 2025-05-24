#include "presentation.h"
#include <sstream>
#include <vector>

int getDurationInMinutes(const Presentation& p) {
    int h1, m1, h2, m2;
    char colon;
    std::istringstream ss1(p.timeStart), ss2(p.timeEnd);
    ss1 >> h1 >> colon >> m1;
    ss2 >> h2 >> colon >> m2;
    return (h2 * 60 + m2) - (h1 * 60 + m1);
}
bool compareByStartTime(const Presentation& a, const Presentation& b) {
    return a.timeStart < b.timeStart;
}

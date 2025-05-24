#include "presentation.h"

bool compareByStartTime(const Presentation& a, const Presentation& b) {
    return a.timeStart < b.timeStart;
}

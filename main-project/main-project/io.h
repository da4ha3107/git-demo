#pragma once
#include <vector>
#include <string>
#include "presentation.h"

std::vector<Presentation> readPresentations(const std::string& filename);
void searchBySpeaker(const std::vector<Presentation>& presentations, const std::string& name);


#pragma once
#include "presentation.h"

typedef bool (*CompareFunc)(const Presentation*, const Presentation*);
typedef void (*SortFunc)(Presentation* [], int, CompareFunc);

void heapSort(Presentation* arr[], int size, CompareFunc cmp);
void mergeSort(Presentation* arr[], int size, CompareFunc cmp);

bool compareByDurationDesc(const Presentation* a, const Presentation* b);
bool compareByNameAndTopic(const Presentation* a, const Presentation* b);
#pragma once

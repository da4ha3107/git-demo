#include "sort.h"
#include <algorithm>
#include <vector>

bool compareByDurationDesc(const Presentation* a, const Presentation* b) {
    return getDurationInMinutes(*a) > getDurationInMinutes(*b);
}

bool compareByNameAndTopic(const Presentation* a, const Presentation* b) {
    if (a->speakerFullName != b->speakerFullName)
        return a->speakerFullName < b->speakerFullName;
    return a->topic < b->topic;
}

void heapify(Presentation* arr[], int n, int i, CompareFunc cmp) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && cmp(arr[l], arr[largest])) largest = l;
    if (r < n && cmp(arr[r], arr[largest])) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, cmp);
    }
}

void heapSort(Presentation* arr[], int size, CompareFunc cmp) {
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(arr, size, i, cmp);
    for (int i = size - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, cmp);
    }
}

void merge(Presentation* arr[], int left, int mid, int right, CompareFunc cmp) {
    int n1 = mid - left + 1, n2 = right - mid;
    std::vector<Presentation*> L(arr + left, arr + mid + 1);
    std::vector<Presentation*> R(arr + mid + 1, arr + right + 1);
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = cmp(L[i], R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortRec(Presentation* arr[], int left, int right, CompareFunc cmp) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortRec(arr, left, mid, cmp);
        mergeSortRec(arr, mid + 1, right, cmp);
        merge(arr, left, mid, right, cmp);
    }
}

void mergeSort(Presentation* arr[], int size, CompareFunc cmp) {
    mergeSortRec(arr, 0, size - 1, cmp);
}

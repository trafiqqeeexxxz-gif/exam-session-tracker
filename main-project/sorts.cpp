#include "sorts.h"
#include <algorithm>

using namespace std;

void insertionSort(vector<StudentSession*>& sessions, ComparatorFunc comparator) {
    for (size_t i = 1; i < sessions.size(); ++i) {
        StudentSession* key = sessions[i];
        int j = i - 1;

        while (j >= 0 && comparator(sessions[j], key) > 0) {
            sessions[j + 1] = sessions[j];
            j--;
        }
        sessions[j + 1] = key;
    }
}

void merge(vector<StudentSession*>& sessions, int left, int mid, int right, ComparatorFunc comparator) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<StudentSession*> L(n1);
    vector<StudentSession*> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = sessions[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = sessions[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (comparator(L[i], R[j]) <= 0) {
            sessions[k] = L[i];
            i++;
        }
        else {
            sessions[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        sessions[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        sessions[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(vector<StudentSession*>& sessions, int left, int right, ComparatorFunc comparator) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(sessions, left, mid, comparator);
        mergeSortRecursive(sessions, mid + 1, right, comparator);
        merge(sessions, left, mid, right, comparator);
    }
}

void mergeSort(vector<StudentSession*>& sessions, ComparatorFunc comparator) {
    if (!sessions.empty()) {
        mergeSortRecursive(sessions, 0, sessions.size() - 1, comparator);
    }
}
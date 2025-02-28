#ifndef STATS_H
#define STATS_H

#include <algorithm>
#include <iostream>

// Function to calculate the sum of elements in an array
inline int sum(const int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total;
}

// Function to calculate the average of elements in an array
inline double average(const int arr[], int size) {
    if (size == 0) return 0;
    return static_cast<double>(sum(arr, size)) / size;
}

// Function to calculate the median of elements in an array
inline double median(int arr[], int size) {
    if (size == 0) return 0;
    std::sort(arr, arr + size);
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

// Function to calculate the mode of elements in an array
inline int mode(const int arr[], int size) {
    if (size == 0) return 0;
    int maxCount = 0, modeValue = arr[0];
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (arr[j] == arr[i]) {
                ++count;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            modeValue = arr[i];
        }
    }
    return modeValue;
}

#endif // STATS_H
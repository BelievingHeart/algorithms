//
// Created by Afterburner on 2019-02-18.
//


#include <iostream>

inline void swap(int& a, int& b){
    const int c = a;
    a = b;
    b = c;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[++i], arr[high]);
    return i;
}

void quick_sort(int arr[], int low, int high){
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main()
{
    int arr[] = {9, 4 ,4, 7, 3, 9, 2, 5, 1, 0};
    quick_sort(arr, 0, 9);
    for (const auto &ele : arr) {
        std::cout << ele << ' ';
    }
}

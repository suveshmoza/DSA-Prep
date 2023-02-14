#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArr(vector<int> arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    printArr(arr);
    quickSort(arr, 0, arr.size() - 1);
    printArr(arr);
}
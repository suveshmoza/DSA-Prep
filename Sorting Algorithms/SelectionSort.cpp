#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[minIdx], arr[i]);
        }
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
    selectionSort(arr);
    printArr(arr);
}
#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr);
    printArr(arr);
}
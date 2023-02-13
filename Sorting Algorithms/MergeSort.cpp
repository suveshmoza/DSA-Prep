#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp(r - l + 1);
    int i, j, k;
    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= m) {
        temp[k++] = arr[i++];
    }
    while (j <= r) {
        arr[k++] = arr[j++];
    }
    for (k = l; k <= r; k++) {
        arr[k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    mergeSort(arr, 0, arr.size() - 1);
    printArr(arr);
}
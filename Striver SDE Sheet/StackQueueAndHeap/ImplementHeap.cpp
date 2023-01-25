#include <climits>
#include <iostream>
using namespace std;

class MinHeap {
    int *arr;
    int maxSize;
    int heapSize;

   public:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int getMin() { return arr[0]; }

    MinHeap(int cap) {
        heapSize = 0;
        maxSize = cap;
        arr = new int[cap];
    }

    void insertKey(int k) {
        if (heapSize == maxSize) {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }
        heapSize++;
        int i = heapSize - 1;
        arr[i] = k;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_val) {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int extractMin() {
        if (heapSize <= 0)
            return INT_MAX;
        if (heapSize == 1) {
            heapSize--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        MinHeapify(0);

        return root;
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heapSize && arr[l] < arr[i])
            smallest = l;
        if (r < heapSize && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            MinHeapify(smallest);
        }
    }
};

int main() {
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " " << endl;
    cout << h.getMin() << " " << endl;
    h.decreaseKey(2, 1);
    cout << h.getMin() << endl;
    return 0;
}

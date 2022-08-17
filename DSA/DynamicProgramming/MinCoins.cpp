// Greedy
int findMinimumCoins(int amount) {
    vector<int> C = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int count = 0;
    for (int i = C.size() - 1; i >= 0; i--) {
        while (amount >= C[i]) {
            amount -= C[i];
            count++;
        }
    }
    return count;
}

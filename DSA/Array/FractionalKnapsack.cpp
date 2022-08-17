static bool comp(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, comp);

    double maxProfit = 0.0;
    int currW = 0;

    for (int i = 0; i < n; i++) {
        if (currW + arr[i].weight <= W) {
            currW += arr[i].weight;
            maxProfit += arr[i].value;
        } else {
            int remaining = W - currW;
            maxProfit += (arr[i].value / (double)arr[i].weight) * (double)remaining;
            break;
        }
    }

    return (double)maxProfit;
}
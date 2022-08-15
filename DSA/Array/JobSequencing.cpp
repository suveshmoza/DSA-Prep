static bool comp(Job a, Job b) {
    return (a.profit > b.profit);
}

vector<int> JobScheduling(Job arr[], int n) {
    vector<int> v;
    sort(arr, arr + n, comp);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i].dead);
    }
    vector<int> slot(maxi, -1);
    int count_job = 0, job_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].dead; j >= 1; j--) {
            if (slot[j] == -1) {
                job_profit += arr[i].profit;
                count_job++;
                slot[j] = i;
                break;
            }
        }
    }
    v.push_back(count_job);
    v.push_back(job_profit);
    return v;
}
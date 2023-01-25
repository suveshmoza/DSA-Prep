//* Using minHeap
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

//* Using Quick-Select

int partition(vector<int>& nums, int start, int end) {
    int pivot = start, temp;
    while (start <= end) {
        while (start <= end && nums[start] <= nums[pivot]) start++;
        while (start <= end && nums[end] > nums[pivot]) end--;
        if (start > end) break;
        swap(nums[start], nums[end]);
    }
    swap(nums[pivot], nums[end]);
    return end;
}

int findKthLargest(vector<int>& nums, int k) {
    int low = 0, high = nums.size() - 1;
    k = nums.size() - k;
    int idx = 0;
    while (low <= high) {
        idx = partition(nums, low, high);
        if (idx == k) {
            break;
        } else if (idx < k)
            low = idx + 1;
        else
            high = idx - 1;
    }
    return nums[idx];
}
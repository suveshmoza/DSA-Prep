//* Approach-1

int trap(vector<int>& height) {
    stack<int> st;
    int n = height.size(), water = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int index = st.top();
            st.pop();
            if (st.empty()) break;
            int h = min(height[i], height[st.top()]) - height[index];
            int w = i - st.top() - 1;
            water += h * w;
        }
        st.push(i);
    }
    return water;
}

//* Approach 2

int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                res += (leftMax - height[left]);
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                res += (rightMax - height[right]);
            right--;
        }
    }
    return res;
}
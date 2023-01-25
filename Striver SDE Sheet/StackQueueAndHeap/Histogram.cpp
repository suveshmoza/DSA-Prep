//* Brute
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;
    st.push(0);
    left[0] = -1;
    for (int i = 1; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        left[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    st.push(n - 1);
    right[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        right[i] = (st.empty()) ? n : st.top();
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        if (area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}
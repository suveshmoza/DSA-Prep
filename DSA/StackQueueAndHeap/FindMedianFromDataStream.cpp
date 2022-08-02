class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Adding elements to heap
        if (maxHeap.empty() || num<maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);
        
        // Balancing heaps
        if (maxHeap.size()>minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size()<minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size()==maxHeap.size()) return (minHeap.top()+maxHeap.top())/2.0;
        else return maxHeap.top();
    }
};
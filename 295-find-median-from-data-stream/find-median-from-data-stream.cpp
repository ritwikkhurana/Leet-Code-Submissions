class MedianFinder {
public:
    int totalSize;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        while (!maxHeap.empty()) maxHeap.pop();
        while(!minHeap.empty()) minHeap.pop();
        totalSize = 0;
    }
    
    void addNum(int num) {
        totalSize++;
        if (totalSize % 2 == 0) {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else {
            if (maxHeap.empty()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
                while (minHeap.top() < maxHeap.top()) {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(temp);
                }
            }
        }
    }
    
    double findMedian() {
        if (totalSize % 2 == 0) {
            int num1 = maxHeap.top();maxHeap.pop();
            int num2 = maxHeap.top();
            maxHeap.push(num1);
            return (double)(num1+num2)/2.0;
        } else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int i: nums) {
            if (pq.size() < size) {
                pq.push(i);
            } else {
               if (i > pq.top()) {
                pq.pop();
                pq.push(i);
               } 
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < size) {
            pq.push(val);
        } else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
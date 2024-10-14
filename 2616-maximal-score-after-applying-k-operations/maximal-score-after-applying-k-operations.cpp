class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for (int i: nums) {
            pq.push(i);
        }
        for (int i = 0 ; i < k ; i++) {
            int ele = pq.top();pq.pop();
            ans += ele;
            ele = ele%3 == 0 ? ele/3 : (ele/3)+1;
            pq.push(ele);
        }   
        return ans;
    }
};
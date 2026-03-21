class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> dist;
        int start=0,end=0;
        long long sum=0,maxSum=0;
        while (end < nums.size()) {
            dist[nums[end]]++;
            sum += nums[end];
            if (end-start+1 == k) {
                if (dist.size() == k) {
                    if (sum > maxSum) maxSum = sum;
                }
                dist[nums[start]]--;
                if (dist[nums[start]] == 0) dist.erase(nums[start]);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return maxSum;
    }
};
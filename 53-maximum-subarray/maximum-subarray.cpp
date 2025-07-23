class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=nums[0],prevMax=0;
        for (int i = 0 ; i < nums.size() ; i++) {
            sum += nums[i];
            prevMax = max(nums[i],max(sum,prevMax+nums[i]));
            ans = max(ans,prevMax);
        }
        return ans;
    }
};
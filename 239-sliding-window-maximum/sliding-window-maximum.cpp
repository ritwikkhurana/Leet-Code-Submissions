class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> ourmap;
        int n = nums.size();
        vector<int> output;
        for (int i = 0 ; i < k ; i++) {
            ourmap[nums[i]]++;
        }
        output.push_back(ourmap.rbegin()->first);
        for (int i = k ; i < n ; i++) {
            ourmap[nums[i]]++;
            ourmap[nums[i-k]]--;
            if (ourmap[nums[i-k]] == 0) ourmap.erase(nums[i-k]);
            output.push_back(ourmap.rbegin()->first);
        }
        return output;
    }
};
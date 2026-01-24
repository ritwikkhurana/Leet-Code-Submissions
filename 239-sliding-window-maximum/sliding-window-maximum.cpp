class Desc {
public:
    bool operator() (int a, int b) const {
        return a > b;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int, Desc> m;
        int n = nums.size();
        vector<int> output;
        for (int i = 0 ; i < k ; i++) {
            m[nums[i]]++;
        }
        output.push_back(m.begin() -> first);
        for (int i = k ; i < n ; i++) {
            m[nums[i-k]]--;
            if (m[nums[i-k]] == 0) m.erase(nums[i-k]);
            m[nums[i]]++;
            output.push_back(m.begin() -> first);
        }
        return output;
    }
};
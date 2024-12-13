class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long finalScore = 0;
        map<int,vector<int>> ourmap;
        unordered_set<int> marked;
        for (int i = 0 ; i < nums.size(); i++) {
            ourmap[nums[i]].push_back(i);
        }
        for (auto i: ourmap) {
            int val = i.first;
            for (auto index : i.second) {
                if (marked.find(index) == marked.end()) {
                    finalScore += (long long)(val);
                    marked.insert(index);
                    if (index-1 >= 0) marked.insert(index-1);
                    if (index+1 < nums.size()) marked.insert(index+1);
                }
            }
        }
        return finalScore;
    }
};
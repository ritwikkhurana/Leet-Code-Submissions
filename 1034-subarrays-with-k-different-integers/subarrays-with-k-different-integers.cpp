class Solution {
public:
    int countSub(vector<int> &s, int k) {
        int n = s.size();
        unordered_map<int,int> ourmap;
        int total = 0;
        int start=0,end=0;
        while (end < n) {
            ourmap[s[end]]++;
            while (ourmap.size() > k) {
                ourmap[s[start]]--;
                if (ourmap[s[start]] == 0) ourmap.erase(s[start]);
                start++;
            }
            total += (end-start+1);
            end++;
        }
        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSub(nums,k) - countSub(nums,k-1);
    }
};
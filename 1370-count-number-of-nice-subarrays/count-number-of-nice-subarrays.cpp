class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> ourmap;
        int sub=0;
        int odd=0;
        for (int i: nums) {
            if (i%2==1) odd++;
            if (odd==k) sub++;
            sub+= (ourmap[odd-k]);
            ourmap[odd]++;
        }
        return sub;
    }
};
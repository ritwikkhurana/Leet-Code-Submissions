class Solution {
public:
    void help(vector<int> &nums, int l, unordered_map<int,int> &ourmap, int &count, int n, int k) {
        if (l >= n) {
            count++;
            return;
        }
        if (ourmap[nums[l] + k] > 0 || ourmap[nums[l]-k] > 0) {
            help(nums,l+1,ourmap,count,n,k);
        } else {
            ourmap[nums[l]]++;
            help(nums,l+1,ourmap,count,n,k);
            ourmap[nums[l]]--;
            help(nums,l+1,ourmap,count,n,k);
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> ourmap;
        int totalCount=0;
        help(nums, 0, ourmap, totalCount, n,k);
        return totalCount-1;
    }
};
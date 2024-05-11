class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = 0;
        int start = 0;
        while (start < nums1.size()) {
            if (nums1[start] != nums2[start]) {
                ans = nums2[start] - nums1[start];
                break;
            }
            start++;
        }
        return ans;
    }
};
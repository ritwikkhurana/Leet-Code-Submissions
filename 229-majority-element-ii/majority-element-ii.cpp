class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=-1,el2=-1,cnt1=0,cnt2=0;
        for (int i: nums) {
            if (cnt1 == 0 && i != el2) {
                el1 = i;
                cnt1++;
            } else if (cnt2 == 0 && i != el1) {
                el2 = i;
                cnt2++;
            } else if (i == el1) {
                cnt1++;
            } else if (i == el2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> output;
        cnt1=0,cnt2=0;
        for (int i: nums) {
            if (i == el1) {
                cnt1++;
            } else if (i == el2) {
                cnt2++;
            }
        }
        if (cnt1 > nums.size()/3) output.push_back(el1);
        if (cnt2 > nums.size()/3) output.push_back(el2);
        return output;
    }
};
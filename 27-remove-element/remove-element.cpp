class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int notEq = 0;
        for (int i = 0 ; i < n ; i++) {
            if (nums[i] == val) {
                nums[i] = -1;
            } else {
                notEq++;
            }
        }
        int place=0,get=0;
        while (get < n) {
            if (nums[get] != -1) {
                nums[place] = nums[get];
                get++;
                place++;
            } else {
                get++;
            }
        } 
        return notEq;
    }
};
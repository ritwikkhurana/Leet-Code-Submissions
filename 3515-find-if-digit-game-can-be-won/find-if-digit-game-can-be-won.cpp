class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1=0,sum2=0,sum3=0;
        for (int i: nums) {
            if (i >=0 && i <= 9) {
                sum1 += i;
            } else if (i >= 10 && i <= 99) {
                sum2 += i;
            } else {
                sum3 += i;
            }
        }
        if (sum1 > (sum2 + sum3) || sum2 > (sum3 + sum1)) return true;
        return false;
    }
};
class Solution {
public:
    int reverse(int x) {
        int maxVal = pow(2,31) - 1;
        long long newVal = 0;
        bool sign = x < 0 ? true : false;
        int input = abs(x);
        while(input) {
            int rem = input%10;
            newVal = (newVal*10) + rem;
            if (newVal > maxVal) return 0;
            input = input/10;
        }
        if (sign) newVal *= -1;
        return newVal;
    }
};
class Solution {
public:
    int minSwaps(string s) {
        int open = 0,close=0,start=0,end=s.size()-1;
        int swaps = 0;
        while (start <= end) {
            if (s[start] == '[') {
                open++;
            } else {
                close++;
            }
            if (close > open) {
                while (end >= start && s[end] != '[') end--;
                swap(s[start],s[end]);
                swaps++;
                end--;
                open++;
                close--;
            }
            start++;
        }
        return swaps;
    }
};
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long sum = 0;
        unordered_map<int, vector<int>> ourmap;
        for (int i = 0 ; i < nums.size() ; i++) {
            int count = 0;
            while (nums[i]) {
                int dig = nums[i]%10;
                if (ourmap.find(dig) == ourmap.end()) {
                    vector<int> values(12, 0);
                    values[count] = 1;
                    ourmap[dig] = values;
                    sum += (i);
                } else {
                    int total = ourmap[dig][count];
                    sum += (i-total);
                    ourmap[dig][count]++;
                }
                nums[i] = nums[i]/10;
                count++;
            }
        }
        return sum;
    }
};
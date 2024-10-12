class Solution {
public:
    int calVal(string input) {
        int output = 0;
        int mult = 0;
        for (int i = input.size()-1 ; i>=0 ; i--) {
            output += (pow(2,mult)*(input[i]-'0'));
            mult++;
        }
        return output;
    }
    string getBinary(int num) {
        string binary = "";
        int set = 0;
        for (int j = 31 ; j>=0 ; j--) {
            int bit = (num >> j) & 1;
            if (bit) {
                binary.push_back('1');
                set = 1;
            } else if (set) {
                binary.push_back('0');
            }
        }
        return binary;
    }
    void getMax(int num1, int num2, int num3, int &ans) {
        string whole = "";
        whole.append(getBinary(num1));
        whole.append(getBinary(num2));
        whole.append(getBinary(num3));
        ans = max(ans, calVal(whole));
    }
    int maxGoodNumber(vector<int>& nums) {
        int ans = 0;
        getMax(nums[0], nums[1], nums[2], ans);
        getMax(nums[0], nums[2], nums[1], ans);
        getMax(nums[1], nums[0], nums[2], ans);
        getMax(nums[1], nums[2], nums[0], ans);
        getMax(nums[2], nums[1], nums[0], ans);
        getMax(nums[2], nums[0], nums[1], ans);
        return ans;
    }
};
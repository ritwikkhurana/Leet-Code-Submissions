class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> ourmap;
        for (auto i: arr1) {
            string num = to_string(i);
            for (int i = 0 ; i < num.size() ; i++) {
                ourmap[num.substr(0,i+1)] = i+1;
            }
        }
        int maxLen = 0;
        for (auto i: arr2) {
            string num = to_string(i);
            for (int i = num.size()-1 ; i>=0 ; i--) {
                if (ourmap.find(num.substr(0,i+1)) != ourmap.end()) {
                    maxLen = max(maxLen, i+1);
                    break;
                }
            }
        }
        return maxLen;
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen=0,start=0,end=0;
        unordered_map<int,int> count;
        while (end < fruits.size()) {
            count[fruits[end]]++;
            while (count.size() > 2) {
                count[fruits[start]]--;
                if (count[fruits[start]] == 0) count.erase(fruits[start]);
                start++;
            }
            maxLen = max(maxLen, end-start+1);
            end++;
        }
        return maxLen;
    }
};
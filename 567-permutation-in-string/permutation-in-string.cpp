class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1Count;
        unordered_map<char,int> tempCount;
        for (char c: s1) {
            s1Count[c]++;
        }
        tempCount.insert(s1Count.begin(), s1Count.end());
        int start=0,end=0;
        while (end < s2.size()) {
            if (tempCount[s2[end]] > 0) {
                tempCount[s2[end]]--;
                if (end-start+1 == s1.size()) return true;
                end++;
            } else {
                if (start == end) {
                    start++;
                    end++;
                } else {
                    tempCount[s2[start]]++;
                    start++;
                }
            }
        }
        return false;
    }
};
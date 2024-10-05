class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char,int> s1Count;
        unordered_map<char,int> tempCount;
        for (char c: s1) {
            s1Count[c]++;
        }
        for (int i = 0 ; i <= s2.size()-s1.size() ; i++) {
            if (s1Count[s2[i]] > 0) {
                tempCount.insert(s1Count.begin(), s1Count.end());
                tempCount[s2[i]]--;
                bool isMatch = true;
                for (int j = i+1 ; (j-i) < s1.size() ; j++) {
                    if (tempCount[s2[j]] <= 0) {
                        isMatch = false;
                        break;
                    }
                    tempCount[s2[j]]--;
                }
                if (isMatch) return true;
            }
            tempCount.clear();
        }
        return false;
    }
};
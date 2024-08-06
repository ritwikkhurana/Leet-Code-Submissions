class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int totalPush = 0;
        vector<int> charCount(26, 0);
        for (char c: word) {
            charCount[c-'a']++;
        }
        sort(charCount.begin(), charCount.end(), greater<int>());
        int usedCount = 1;
        for (int i: charCount) {
            if (i > 0) {
                totalPush += (usedCount%8 == 0 ? usedCount/8 : usedCount/8+1)*i;
            }
            usedCount++;
        }
        return totalPush;
    }
};
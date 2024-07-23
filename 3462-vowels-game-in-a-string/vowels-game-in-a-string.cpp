class Solution {
public:
    bool doesAliceWin(string s) {
        int countVowel = 0;
        for (char c: s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') countVowel++;
        }
        if (countVowel == 0) return false;
        return true;
    }
};
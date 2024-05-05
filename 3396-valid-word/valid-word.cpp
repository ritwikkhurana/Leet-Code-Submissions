class Solution {
public:
    bool isValid(string word) {
        unordered_set<char> vowels({'a','e','i','o','u','A','E','I','O','U'});
        if (word.size() < 3) return false;
        int vow=0,conso=0;
        for (char c: word) {
           if (c == '@' || c == '#' || c == '$') return false;
           if (vowels.find(c) != vowels.end()) {
            vow++;
           } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            conso++;
           }
        }
        if (vow == 0 || conso == 0) return false;
        return true;  
    }
};
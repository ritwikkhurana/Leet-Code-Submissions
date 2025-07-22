class Solution {
public:
    string makeFancyString(string s) {
        string output;
        for (int i = 0 ; i < s.size() ; i++) {
            if (i < 2 || (s[i] != output[output.size()-2] || s[i] != output[output.size()-1])) {
                output.push_back(s[i]);
            }
        }
        return output;
    }
};
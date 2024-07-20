class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string output;
        for (int i = 0 ; i < n ; i++) {
            output.push_back(s[(i+k)%n]);
        }
        return output;
    }
};
class Solution {
public:
    void generate(string s, unordered_set<string> &hashDict, int start, string word, vector<string> &output) {
        if (start >= s.size()) {
            word.pop_back();
            output.push_back(word);
            return;
        }
        for (int i = start ; i < s.size() ; i++) {
            string prefix = s.substr(start, i-start+1);
            if (hashDict.find(prefix) == hashDict.end()) continue;
            string temp = word;
            word += prefix + " ";
            generate(s, hashDict, i+1, word, output);
            word = temp;
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<string> output;
        unordered_set<string> hashDict;
        for (string word: wordDict) {
            hashDict.insert(word);
        }
        string word = "";
        generate(s, hashDict, 0, word, output);
        return output;
    }
};
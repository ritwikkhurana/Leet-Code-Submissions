class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> ourmap;
        int maxLength = 0;
        for (int i = 0 ; i < word.size() ; i++) {
            if ((i+1)% k == 0) {
                ourmap[word.substr(i-k+1, k)]++;
                maxLength = max(maxLength, ourmap[word.substr(i-k+1, k)]);
            }     
        }
        int totalChunks = word.size()/k;
        return (totalChunks- maxLength);
    }
};
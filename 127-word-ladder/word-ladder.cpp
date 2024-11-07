class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        unordered_set<string> vis;
        for (string word: wordList) {
            dict.insert(word);
        }

        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        vis.insert(beginWord);
        while (!q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (word == endWord) return dist;
            string temp = word;
            for (int i = 0 ; i < word.size() ; i++) {
                char tempChar = temp[i];
                for (int j = 0 ; j < 26 ; j++) {
                    temp[i] = 'a' + j;
                    if (dict.find(temp) != dict.end() && vis.find(temp) == vis.end()) {
                        vis.insert(temp);
                        q.push({temp, dist+1});
                    }
                    temp[i] = tempChar;
                }
            }
        }
        return 0;
    }
};
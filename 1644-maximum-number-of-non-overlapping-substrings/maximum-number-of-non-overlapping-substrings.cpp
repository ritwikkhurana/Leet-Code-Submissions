class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char,pair<int,int>> charCount;
        unordered_map<char, vector<int>> allocc;
        for (int i = 0 ; i < s.size() ; i++) {
            if (charCount.find(s[i]) == charCount.end()) {
                charCount[s[i]] = {i,i};
            } else {
                charCount[s[i]].second = i;
            }
            allocc[s[i]].push_back(i);
        }
        unordered_map<char, pair<int,int>> expCount;
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq; 
        for (int i = 0 ; i < s.size() ; i++) {
            char reqChar = s[i];
            if (expCount.find(reqChar) != expCount.end()) continue;
            int startIndex = charCount[reqChar].first;
            int endIndex = charCount[reqChar].second;
            int index = startIndex;
            while (index < endIndex) {
                char tempChar = s[index];
                if (tempChar == reqChar) {
                    index++;
                    continue;
                }
                int start2 = expCount.find(tempChar) != expCount.end() ? expCount[tempChar].first : charCount[tempChar].first;
                int end2 = expCount.find(tempChar) != expCount.end() ? expCount[tempChar].second : charCount[tempChar].second;
                startIndex = min(startIndex, start2);
                endIndex = max(endIndex, end2);
                index++;
            }
            cout << "Char: " << reqChar << ", Start: " << startIndex << ", End: " << endIndex << endl;
            expCount[reqChar] = {startIndex, endIndex};
            pq.push({endIndex-startIndex+1, reqChar});
        }
        vector<string> output;
        vector<char> eleChar;
        while (!pq.empty()) {
            char reqChar = pq.top().second; pq.pop();
            eleChar.push_back(reqChar);
        }

        for (int i = 0 ; i < eleChar.size() ; i++) {
            bool isEle = true;
            int startIndex = expCount[eleChar[i]].first;
            int endIndex = expCount[eleChar[i]].second;
            for (int j = i-1 ; j>=0 ; j--) {
                int start = expCount[eleChar[j]].first;
                int end = expCount[eleChar[j]].second;
                bool outside = (start > endIndex) || (end < startIndex);
                if (!outside) {
                    isEle = false;
                    break;
                }
            }
            if (isEle) {
                output.push_back(s.substr(startIndex, endIndex-startIndex+1));
            }
        }
        return output;
    }
};
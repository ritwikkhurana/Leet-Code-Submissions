class Solution {
public:
    int getLowerBound(string word, int end, vector<vector<int>> &charCount, int k) {
        int start = 1;
        int right = end;
        int ans = -1;
        while (start <= right) {
            int mid = start + (right-start)/2;
            bool criteriaMatch = true;
            for (int i = 0 ; i < 5 ; i++) {
                if ((charCount[end][i] - charCount[mid-1][i]) < 1) {
                    criteriaMatch = false;
                    break;
                }
            }
            int consoCount = charCount[end][5] - charCount[mid-1][5];
            if (consoCount > k) {
                start = mid+1;
            } else {
                if (criteriaMatch && consoCount == k) ans = mid;
                right = mid-1;
            }
        }
        return ans;
    }

    int getUpperBound(string word, int start, int end, vector<vector<int>> &charCount, int k) {
        int right = end;
        int ans = -1;
        while (start <= right) {
            int mid = start + (right-start)/2;
            int criteriaMatch = true;
            for (int i = 0 ; i < 5 ; i++) {
                if ((charCount[end][i] - charCount[mid-1][i]) < 1) {
                    criteriaMatch = false;
                    break;
                }
            }
            int consoCount = charCount[end][5] - charCount[mid-1][5];
            if (!criteriaMatch || consoCount < k) {
                right = mid-1;
            } else {
                if (consoCount == k) ans = mid;
                start = mid+1;
            }
        }
        return ans;
    }


    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<vector<int>> charCount(n);
        set<char> vowels = {'a','e','i','o','u'};
        int ans = 0;
        unordered_map<char,int> countMap;
        for (int i = 0 ; i < n ; i++) {
            if (vowels.find(word[i]) != vowels.end()) {
                countMap[word[i]]++;
            } else {
                countMap['c']++;
            }
            charCount[i] = {countMap['a'],countMap['e'],countMap['i'],countMap['o'],countMap['u'],countMap['c']};
            bool criteriaMatch = true;
            for (int j = 0 ; j < 5 ; j++) {
                if (charCount[i][j] < 1) {
                    criteriaMatch = false;
                    break;
                }
            }
            if (criteriaMatch && countMap['c'] >= k) {
                if (countMap['c'] == k) ans++;
                int lowerBound = getLowerBound(word, i, charCount, k);
                int upperBound = getUpperBound(word, lowerBound == -1 ? 1 : lowerBound, i, charCount, k);
                if (upperBound != -1 && lowerBound != -1) {
                    ans += (upperBound-lowerBound+1);
                }
            }
        }
        return ans;
    }
};
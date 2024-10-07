class Solution {
public:
    vector<string> splitString(string s, char token) {
        vector<string> output;
        int start=0,end=0;
        while (end < s.size()) {
            while (end < s.size() && s[end] != token) {
                end++;
            }
            output.push_back(s.substr(start, end-start));
            end++;
            start=end;
        }
        return output;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> split1 = splitString(sentence1, ' ');
        vector<string> split2 = splitString(sentence2, ' ');
        int i=0,j=split1.size()-1,k=0,l=split2.size()-1;
        while (i <= j && k <= l) {
            if (split1[i] == split2[k]) {
                i++;
                k++;
            } else if (split1[j] == split2[l]) {
                j--;
                l--;
            } else {
                return false;
            }
        }
        return true;
    }
};
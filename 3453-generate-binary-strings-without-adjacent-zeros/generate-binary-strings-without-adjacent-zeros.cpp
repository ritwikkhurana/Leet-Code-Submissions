class Solution {
public:
    void genString(int n, int i, int flag, string temp, vector<string> &output) {
        if (i >=n ) {
            output.push_back(temp);
            return;
        }
        temp.push_back('1');
        genString(n, i+1, 1, temp, output);
        temp.pop_back();
        if (flag == 1) {
            temp.push_back('0');
            genString(n, i+1, 0, temp, output);
            temp.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> output;
        string temp;
        genString(n, 0, 1, temp, output);
        return output;
    }
};
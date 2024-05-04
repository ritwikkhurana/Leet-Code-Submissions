class Solution {
public:
    bool help(string s1, string s2, string s3, int l1, int l2, int flag, int n, int m,  vector<vector<vector<int>>> &dp) {
        int l3 = l1+l2;
        if (l3 >= s3.size()) return abs(n-m) <= 1 && (l1>=s1.size() && l2>=s2.size());
        if (flag) {
            if (l1 >= s1.size()) return s2.substr(l2) == s3.substr(l3);
            for (int i = l1 ; i<s1.size() ; i++) {
                string str1 = s1.substr(l1,i-l1+1);
                if (s3.substr(l3,str1.size()) != str1) continue;
                bool fetch = i+1 < s1.size() && l2 < s2.size() && dp[i+1][l2][0] != -1 ? dp[i+1][l2][0] : 
                help(s1,s2,s3,i+1,l2,0,n+1,m,dp);
                if (fetch) return dp[l1][l2][flag] = true;
            }
        } else {
            if (l2 >= s2.size()) return s1.substr(l1) == s3.substr(l3);
            for (int i = l2 ; i<s2.size() ; i++) {
                string str1 = s2.substr(l2,i-l2+1);
                if (s3.substr(l3,str1.size()) != str1) continue;
                bool fetch = l1 < s1.size() && i+1 < s2.size() && dp[l1][i+1][1] != -1 ? dp[l1][i+1][1] : help(s1,s2,s3,l1,i+1,1,n,m+1,dp);
                if (fetch) return dp[l1][l2][flag] = true;
            }
        }
        return dp[l1][l2][flag] = false;
    } 
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1, vector<int>(2, -1)));
        return help(s1,s2,s3,0,0,0,0,0,dp) || help(s1,s2,s3,0,0,1,0,0,dp);
    }
};
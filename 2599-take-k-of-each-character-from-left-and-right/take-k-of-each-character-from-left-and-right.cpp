class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> ourmap(3,0);
        for (char c : s) {
            ourmap[c- 'a']++;
        }
        if (*min_element(ourmap.begin(), ourmap.end()) < k) return -1;
        if (k == 0) return 0;
        int n = s.size();
        int ans = n;
        int l=-1,r=0;
        for (r = 0 ; r < n ; r++) {
            int removal = l + (n-r) + 1;
            ans = min(ans, removal);
            ourmap[s[r]- 'a']--;
            while (*min_element(ourmap.begin(), ourmap.end()) < k) {
                l++;
                ourmap[s[l] - 'a']++;
            }
        }
        ans = min(ans, l+1);
        return ans;
    }
};
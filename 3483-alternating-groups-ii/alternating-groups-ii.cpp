class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
       int n = colors.size();
        int total = 0;
        int contg = 1;
        int passed = 0;
        for (int i = 1 ; passed == 0 || i < k-1 ; i = (i+1)%n) {
            int prev = i == 0 ? n-1 : i-1;
            if (colors[i] == colors[prev]) {
                contg = 1;
            } else {
                contg++;
                if (contg == k) {
                    total++;
                    contg--;
                }
            }
            if (i+1 == n) passed = 1;
        }
        return total; 
    }
};
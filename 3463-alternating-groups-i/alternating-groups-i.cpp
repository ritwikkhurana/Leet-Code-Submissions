class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int total = 0;
        for (int i = 0 ; i < n ; i++) {
            int second = (i+1)%n;
            int third = (i+2)%n;
            if (colors[i] == colors[third] && colors[i] != colors[second]) total++;
        }
        return total;
    }
};
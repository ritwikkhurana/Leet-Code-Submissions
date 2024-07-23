class Solution {
public:
    int minChanges(int n, int k) {
        if (n == k) return 0;
        int changes = 0;
        for (int i = 0 ; i < 32 ; i++) {
            int b1 = (1 << i) & n;
            int b2 = (1 << i) & k;
            if (b1 > 0 && b2 == 0) {
                changes++;
            } else if (b1 == 0 && b2 > 0) return -1;
        }
        return changes;
    }
};
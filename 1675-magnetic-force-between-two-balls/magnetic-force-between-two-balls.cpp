class Solution {
public:

    bool canPlace(vector<int> &pos, int dis, int m) {
        int placed = 1;
        int lastPlaced = pos[0];
        for (int i = 1 ; i < pos.size() ; i++) {
            if (pos[i] - lastPlaced >= dis) {
                placed++;
                lastPlaced = pos[i];
            }
            if (placed >= m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int start=1, end= position[n-1]-position[0];
        int maxDis = 0;
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (canPlace(position, mid, m)) {
                maxDis = max(maxDis, mid);
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return maxDis;
    }
};
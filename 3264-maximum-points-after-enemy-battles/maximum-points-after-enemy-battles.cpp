class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int n = enemyEnergies.size();
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int sell=0,gain=n-1;
        long long totalPoints = 0;
        while (sell <= gain) {
            if (currentEnergy >= enemyEnergies[sell]) {
                totalPoints += ((long long)currentEnergy/enemyEnergies[sell]);
                currentEnergy = currentEnergy % enemyEnergies[sell];
            } else if (totalPoints >= 1) {
                currentEnergy += enemyEnergies[gain];
                gain--;
            } else {
                break;
            }
        }   
        return totalPoints;
    }
};
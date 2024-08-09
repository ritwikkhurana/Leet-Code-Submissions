class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sq = 0;
        for (int i = 0 ; i <= n-3 ; i++) {
            for (int j = 0 ; j <= m-3 ; j++) {
                int arr[10] = {0};
                int reqSum = 0;
                bool isMagic = true;
                for (int k = i ; k < i+3 ; k++) {
                    int currSum = 0;
                    for (int l = j ; l < j+3 ; l++) {
                        if (grid[k][l] > 9 || grid[k][l] < 1) {
                            isMagic = false;
                            break;
                        }
                        currSum += grid[k][l];
                        if (arr[grid[k][l]] != 0) {
                            isMagic = false;
                            break;
                        } else {
                            arr[grid[k][l]] = 1;
                        }
                    }
                    if (!isMagic) break;
                    if (reqSum == 0) {
                        reqSum = currSum;
                    } else if (reqSum != currSum) {
                        isMagic = false;
                        break;
                    }
                }
                if (!isMagic) continue;
                for (int k = j ; k < j+3 ; k++) {
                    int currSum = 0;
                    for (int l = i ; l < i+3 ; l++) {
                        currSum += grid[l][k];
                    }
                    if (reqSum != currSum) {
                        isMagic = false;
                        break;
                    }
                }
                if (!isMagic) continue;
                int diagSum = 0;
                for (int k=i,l=j ; k < i+3 && l < j+3 ; k++,l++) {
                    diagSum += grid[k][l];
                }
                if (diagSum != reqSum) continue;
                int antiDiag = 0;
                for (int k =i,l=j+2 ; k < i+3 && l >= j ; k++,l--) {
                    antiDiag += grid[k][l];
                }
                if (antiDiag != reqSum) continue;
                sq++; 
            }
        }
        return sq;
    }
};
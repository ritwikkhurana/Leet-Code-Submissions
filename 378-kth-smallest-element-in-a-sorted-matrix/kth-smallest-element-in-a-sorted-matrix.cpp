class Solution {
public:

    int countElements(vector<vector<int>>& matrix, int ele) {
        int row=matrix.size()-1,col=0;
        int count = 0;
        while (row >= 0 && col < matrix.size()) {
            if (matrix[row][col] > ele) {
                row--;
            } else {
                count += row+1;
                col++;
            }
        }
        return count; 
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start=matrix[0][0], end=matrix[n-1][n-1];
        int ans = 0;  
        while (start <= end) {
            int mid = start + (end-start)/2;
            int count = countElements(matrix, mid);
            if (count >= k) {
                ans = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }
};
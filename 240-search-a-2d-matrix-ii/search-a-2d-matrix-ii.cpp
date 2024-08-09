class Solution {
public:
    int binarySearch(vector<vector<int>> &matrix, int target, int start, int end, int row) {
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (matrix[row][mid] == target) return mid;
            if (matrix[row][mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return end;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int end = matrix[0].size()-1;
        for (int i = 0 ; i < n ; i++) {
            int val = binarySearch(matrix, target, 0, end, i);
            if (val < 0 || val >= m) return false;
            if (matrix[i][val] == target) return true;
            end = val;
        }
        return false;
    }
};
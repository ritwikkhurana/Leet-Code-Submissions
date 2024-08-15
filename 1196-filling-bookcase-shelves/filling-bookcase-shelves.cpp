class Solution {
public:
    int solve(vector<vector<int>> &books, int currWidth, int maxWidth, int row, int currMax, vector<vector<int>> &dp) {
        if (row >= books.size()) return 0;
        if (dp[row][currWidth] != -1) return dp[row][currWidth];
        if (books[row][0] > currWidth) {
            return dp[row][currWidth] = books[row][1] + solve(books, maxWidth-books[row][0], maxWidth, row+1, books[row][1], dp);
        } else {
            return dp[row][currWidth] = min(books[row][1] + solve(books, maxWidth-books[row][0], maxWidth, row+1, books[row][1], dp),
            (books[row][1] <= currMax ? 0 : books[row][1]-currMax) + solve(books, currWidth-books[row][0], maxWidth, row+1, max(books[row][1],currMax), dp)
            );
        }
    } 
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n+1, vector<int>(shelfWidth+1, -1));
        return solve(books, shelfWidth, shelfWidth, 0, 0, dp);
    }
};
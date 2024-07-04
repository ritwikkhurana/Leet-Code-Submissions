class Solution {
public:
    bool checkPossible(vector<string> &board, int row, int col) {
        int n = board.size();
        // check row and col
        for (int i = 0 ; i < n ; i++) {
            if (board[row][i] == 'Q') return false;
            if (board[i][col] == 'Q') return false;
        }

        // check diag
        for (int i = row,j=col ; i>=0 && j>=0 ; i--,j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i=row,j=col ; i<n && j<n ; i++,j++) {
            if (board[i][j] == 'Q') return false;
        }

        // check anti diag
        for (int i=row,j=col ; i>=0 && j<n ; i--,j++) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i=row,j=col ; i<n && j>=0 ; i++,j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(vector<string> &board, int row, vector<vector<string>> &output) {
        int n = board.size();
        if (row >= n) {
            output.push_back(board);
            return;
        }
        for (int i = 0 ; i < n ; i++) {
            if (!checkPossible(board,row,i)) continue;
            board[row][i] = 'Q';
            solve(board,row+1, output);
            board[row][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> board(n, string(n, '.'));
        solve(board, 0, output);
        return output;
    }
};
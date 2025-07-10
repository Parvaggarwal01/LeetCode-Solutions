class Solution {
public:
    void solve(int n, int row, vector<string>& board, vector<vector<string>>& res,
               vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;
            solve(n, row + 1, board, res, cols, diag1, diag2);
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
        solve(n, 0, board, res, cols, diag1, diag2);
        return res;
    }
};

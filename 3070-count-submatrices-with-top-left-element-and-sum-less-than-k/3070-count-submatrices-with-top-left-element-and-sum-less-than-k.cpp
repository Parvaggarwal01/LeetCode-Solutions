class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> curr(n, 0), prev(n, 0);
        int count = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                long long val = grid[r][c];

                long long up = (r > 0) ? prev[c] : 0;
                long long left = (c > 0) ? curr[c - 1] : 0;
                long long diag = (r > 0 && c > 0) ? prev[c - 1] : 0;

                curr[c] = val + up + left - diag;

                if (curr[c] <= k) count++;
            }
            prev = curr;
        }

        return count;
    }
};
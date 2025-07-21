class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // BFS function
        auto bfs = [&](int startX, int startY) {
            queue<pair<int, int>> q;
            q.push({startX, startY});
            grid[startX][startY] = '0';  // Mark visited

            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (auto [dx, dy] : directions) {
                    int newX = x + dx, newY = y + dy;
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == '1') {
                        q.push({newX, newY});
                        grid[newX][newY] = '0';  // Mark visited
                    }
                }
            }
        };

        // Grid traversal
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(i, j);  // Explore the full island
                }
            }
        }

        return count;
    }
};

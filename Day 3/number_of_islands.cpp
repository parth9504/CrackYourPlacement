class Solution {
public:
    vector<pair<int, int>> v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<int>>&visited) {
        visited[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int new_row = r + v[i].first;
            int new_col = c + v[i].second;
            // check for valid new_row new_col
            if (new_row >= 0 && new_row < grid.size() && new_col >= 0 &&
                new_col < grid[0].size() && grid[new_row][new_col] == '1' &&
                visited[new_row][new_col] == -1) {
                dfs(new_row, new_col, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int i, j, count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == -1) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }
};
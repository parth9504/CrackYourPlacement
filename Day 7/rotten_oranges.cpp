class Solution 
{
    public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>> q; // The queue stores the cell coordinates and the time step.
        int freshOranges = 0;
        
        // Initialize the queue with all the initially rotten oranges.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 0;
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        int time = 0;

        // Perform BFS.
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            time = max(time, t);

            for (const auto& dir : directions) {
                int new_row = r + dir.first;
                int new_col = c + dir.second;

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                    grid[new_row][new_col] == 1 && visited[new_row][new_col] == -1) {
                    grid[new_row][new_col] = 2;
                    visited[new_row][new_col] = t + 1;
                    q.push({{new_row, new_col}, t + 1});
                    freshOranges--;
                }
            }
        }

        return freshOranges == 0 ? time : -1;
    }
};
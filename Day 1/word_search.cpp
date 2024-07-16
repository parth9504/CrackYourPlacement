class Solution {
public:
    vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool dfs(int r, int c, vector<vector<char>>& board, string word, int index, 
    vector<vector<bool>>& visited) {
        if (index == word.size()) {
            return true;
        }
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() 
        || visited[r][c] || board[r][c] != word[index]) {
            return false;
        }
        
        visited[r][c] = true;
        for (int i=0;i<4;i++) {
            int new_row = r + v[i].first;
            int new_col = c + v[i].second;
            if (dfs(new_row, new_col, board, word, index + 1, visited)) {
                return true;
            }
        }
        visited[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(i, j, board, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

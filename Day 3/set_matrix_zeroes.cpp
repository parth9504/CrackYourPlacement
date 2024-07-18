class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // find the indices where 0's are present
        unordered_set<int> row, col;
        int i,j;
        int m = matrix.size(), n = matrix[0].size();
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (auto it : row) {
            // set row to to 0..
            for (i = 0; i < n; i++) {
                matrix[it][i] = 0;
            }
        }
        for (auto it : col) {
            // set col to 0
            for (i = 0; i < m; i++) {
                matrix[i][it] = 0;
            }
        }
    }
};

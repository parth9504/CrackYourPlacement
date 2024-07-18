class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // find the transpose of the marix..
        int i, j;
        int n = matrix.size();
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        // swap the columns..(1st with last) (2nd with 2nd last)...
        // if n is even swap till n/2.. if n is odd, middle column  will remain
        // as it is
        for (i = 0, j = n - 1; i < n / 2; i++, j--) {
            for (int k = 0; k < n; k++) {
                swap(matrix[k][i], matrix[k][j]);
            }
        }
    }
};

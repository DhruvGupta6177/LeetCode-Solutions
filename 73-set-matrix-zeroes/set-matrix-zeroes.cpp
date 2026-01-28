class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int n = matrix.size();
        int m = matrix[0].size();

        // Determine if first row or first col initially contain zero
        bool firstRowZero = false, firstColZero = false;
        for (int j = 0; j < m; ++j) if (matrix[0][j] == 0) { firstRowZero = true; break; }
        for (int i = 0; i < n; ++i) if (matrix[i][0] == 0) { firstColZero = true; break; }

        // Use first row/col as markers for other rows/cols
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero cells based on markers
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero first row/col if needed
        if (firstRowZero) {
            for (int j = 0; j < m; ++j) matrix[0][j] = 0;
        }
        if (firstColZero) {
            for (int i = 0; i < n; ++i) matrix[i][0] = 0;
        }
    }
};

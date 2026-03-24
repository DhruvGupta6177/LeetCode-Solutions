class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int m = grid.size();
        int n = grid[0].size();

        int size = m * n;
        vector<long long> arr(size);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i * n + j] = grid[i][j] % mod;
            }
        }

        vector<long long> prefix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }

        vector<long long> suffix(size, 1);
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }


        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < size; i++) {
            int val = (prefix[i] * suffix[i]) % mod;
            result[i / n][i % n] = val;
        }

        return result;
    }
};
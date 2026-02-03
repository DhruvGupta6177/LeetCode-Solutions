class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int start, int k, int n) {
        if (k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }
        if (k < 0 || n < 0) return;

        for (int i = start; i <= 9; i++) {
            temp.push_back(i);
            backtrack(i + 1, k - 1, n - i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, k, n);
        return ans;
    }
};
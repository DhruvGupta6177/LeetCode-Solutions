class Solution {
public:
    void solve(int open, int close, string current, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        if (open > 0) {
            solve(open - 1, close, current + "(", result);
        }

    
        if (close > open) {
            solve(open, close - 1, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, n, "", result);
        return result;
    }
};

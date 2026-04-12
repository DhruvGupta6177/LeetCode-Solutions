class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression];

        vector<int> results;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
     
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftRes = diffWaysToCompute(left);
                vector<int> rightRes = diffWaysToCompute(right);

                for (int l : leftRes) {
                    for (int r : rightRes) {
                        if (op == '+') results.push_back(l + r);
                        else if (op == '-') results.push_back(l - r);
                        else results.push_back(l * r);
                    }
                }
            }
        }


        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        return memo[expression] = results;
    }
};
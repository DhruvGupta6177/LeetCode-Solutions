class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[py] = px;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int> emailToAccount;

        // Step 1: Union accounts sharing emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAccount.count(email)) {
                    unite(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }

        // Step 2: Group emails by root account
        unordered_map<int, set<string>> groups;

        for (auto &it : emailToAccount) {
            int root = find(it.second);
            groups[root].insert(it.first);
        }

        // Step 3: Build result
        vector<vector<string>> result;
        for (auto &g : groups) {
            vector<string> account;
            account.push_back(accounts[g.first][0]); // name
            for (auto &email : g.second)
                account.push_back(email);
            result.push_back(account);
        }

        return result;
    }
};

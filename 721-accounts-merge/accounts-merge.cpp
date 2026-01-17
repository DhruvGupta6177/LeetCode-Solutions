class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;

        // Step 1: Union accounts by common email
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.UnionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2: Group emails by parent
        vector<vector<string>> mergedMail(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUpar(it.second);
            mergedMail[node].push_back(mail);
        }

        // Step 3: Build answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty())
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]); // name
            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

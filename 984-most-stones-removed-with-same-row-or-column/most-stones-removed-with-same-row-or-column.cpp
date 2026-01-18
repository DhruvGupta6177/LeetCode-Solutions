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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0;
        int maxcol = 0;
        for(auto it : stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        DisjointSet ds(maxrow + maxcol + 1);
        unordered_map<int, int> stoneNodes;
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.UnionBySize(noderow, nodecol);
            stoneNodes[noderow] = 1;
            stoneNodes[nodecol] = 1;
        }

        int cnt = 0;
        for(auto it : stoneNodes) {
            if(ds.findUpar(it.first) == it.first) {
                cnt++;
            }
        }

        return n-cnt;
    }
};
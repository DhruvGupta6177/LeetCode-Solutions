class Solution {
public:
    vector<int> parent, rank;

    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0);

        
        for (int i = 0; i < n; i++)
            parent[i] = i;

        
        for (auto &c : connections) {
            unite(c[0], c[1]);
        }

       
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        
        return components - 1;
    }
};

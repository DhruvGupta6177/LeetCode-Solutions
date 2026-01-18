class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
private:
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        // STEP 1: Union all existing 1s
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int node = r * n + c;
                        int adjNode = nr * n + nc;
                        ds.UnionBySize(node, adjNode);
                    }
                }
            }
        }

        // STEP 2: Try flipping each 0
        int mx = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) continue;

                set<int> components;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        components.insert(ds.findUpar(nr * n + nc));
                    }
                }

                int totalSize = 1;
                for (auto it : components) {
                    totalSize += ds.size[it];
                }

                mx = max(mx, totalSize);
            }
        }

        // STEP 3: If grid has no zero
        for (int i = 0; i < n * n; i++) {
            mx = max(mx, ds.size[ds.findUpar(i)]);
        }

        return mx;
    }
};

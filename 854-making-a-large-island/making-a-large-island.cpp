class Solution {
public:
    int n;
    vector<vector<int>> grid;
    unordered_map<int, int> islandSize;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int r, int c, int id) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1)
            return 0;

        grid[r][c] = id;
        int size = 1;

        for (auto &d : dirs)
            size += dfs(r + d[0], c + d[1], id);

        return size;
    }

    int largestIsland(vector<vector<int>>& gridInput) {
        grid = gridInput;
        n = grid.size();
        int id = 2;   

        // Step 1: Label islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    islandSize[id] = dfs(i, j, id);
                    id++;
                }
            }
        }

        int maxIsland = 0;

        // Step 2: Try flipping each 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int size = 1;

                    for (auto &d : dirs) {
                        int x = i + d[0], y = j + d[1];
                        if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] > 1) {
                            if (!seen.count(grid[x][y])) {
                                size += islandSize[grid[x][y]];
                                seen.insert(grid[x][y]);
                            }
                        }
                    }
                    maxIsland = max(maxIsland, size);
                }
            }
        }

        // Step 3: If no 0 found
        if (maxIsland == 0)
            return n * n;

        return maxIsland;
    }
};

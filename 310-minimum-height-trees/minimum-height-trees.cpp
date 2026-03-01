class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        // Build graph
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;

        // Push all leaves
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1)
                q.push(i);
        }

        int remainingNodes = n;

        // Trim leaves level by level
        while(remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;

            while(size--) {
                int leaf = q.front();
                q.pop();

                for(int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if(degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while(!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};
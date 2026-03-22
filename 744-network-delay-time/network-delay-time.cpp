class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for (auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

      
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            if(currTime > dist[node]) continue;

            for(auto &p : adj[node]) {
                int nxt = p.first;
                int w = p.second;

                if(dist[node] + w < dist[nxt]) {
                    dist[nxt] = dist[node] + w;
                    pq.push({dist[nxt], nxt});
                }
            }
        }

    
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1; 
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};

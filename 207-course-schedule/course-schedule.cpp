class Solution {
public:
    bool isCycleDfs(int src, vector<vector<int>> &edges, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i < edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src){
                if(!vis[v]){
                    if(isCycleDfs(v, edges, vis, recPath)){
                        return true;
                    }
                }

                else if(recPath[v]){
                    return true;
                }
            }
            
        }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n , false);
        vector<bool> recPath(n, false);

        for(int i = 0; i < n;i++){
            if(!vis[i]){
                if(isCycleDfs(i, edges, vis, recPath)){
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntFresh = 0;
        int tm = 0;

        // Push all initially rotten oranges to queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1) cntFresh++;
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   grid[nr][nc] == 1 && vis[nr][nc] == 0){
                    vis[nr][nc] = 2;
                    q.push({{nr, nc}, t + 1});
                    cnt++;
                }
            }
        }

        if(cnt != cntFresh) return -1;
        return tm;
    }
};

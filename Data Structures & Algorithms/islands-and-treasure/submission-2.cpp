class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int R = grid.size();
        int C = grid[0].size();

        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while(!q.empty())
        {
            auto [r, c] = q.front(); q.pop();
            for(int d = 0; d<4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr>=R || nr<0 || nc<0 || nc>=C || grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = 1 + grid[r][c];
                q.push({nr, nc});
            }
        }
    }
};

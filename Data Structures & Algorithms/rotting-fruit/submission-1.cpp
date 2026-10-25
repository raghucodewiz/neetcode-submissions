class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int R = grid.size();
        int C = grid[0].size();

        int fresh = 0;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int minutes = 0;
        while(!q.empty() && fresh>0)
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                auto [r, c] = q.front(); q.pop();
                for(int d = 0; d<4; d++)
                {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr>=0 && nr<R && nc>=0 && nc<C && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ?  minutes : -1;
    }
};

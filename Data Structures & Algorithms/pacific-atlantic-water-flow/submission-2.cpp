class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights)
    {
        int R = heights.size();
        int C = heights[0].size();
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while(!q.empty())
        {
            auto [r, c] = q.front(); q.pop();
            ocean[r][c] = 1;

            for(int d =0;d<4;d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr>=0 && nr<R && nc>=0 && nc<C && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
                {
                    q.push({nr, nc});
                }
            }

        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        vector<vector<bool>> pac(R, vector<bool>(C, 0));//visited by pac
        vector<vector<bool>> atl(R, vector<bool>(C, 0));//visited by atl

        queue<pair<int, int>> pacq, atlq;

        for(int r=0;r<R;r++)
        {
            pacq.push({r, 0});
            atlq.push({r, C-1});
        }
        for(int c=0;c<C;c++)
        {
            pacq.push({0, c});
            atlq.push({R-1, c});
        }

        bfs(pacq, pac, heights);
        bfs(atlq, atl, heights);

        vector<vector<int>> res;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

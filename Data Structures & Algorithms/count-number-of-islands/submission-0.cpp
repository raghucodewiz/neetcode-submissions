class Solution {
    //int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        int ans = 0;

        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int R = grid.size();
        int C = grid[0].size();
        if(r<0 || c<0 || r>=R || c >= C || grid[r][c] != '1') return;

        grid[r][c] = '0';

        dfs(grid, r+1, c);

        dfs(grid, r-1, c);

        dfs(grid, r, c+1);

        dfs(grid, r, c-1);
    }
};

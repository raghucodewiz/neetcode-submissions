class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        int R = grid.size();
        int C = grid[0].size();

        if(r<0 || r>=R || c<0 || c>=C || grid[r][c] != 1) return 0;

        grid[r][c] = 0;
        int res = 1;

        res +=dfs(grid, r+1, c) + dfs(grid, r-1, c) + dfs(grid, r, c+1) + dfs(grid, r, c-1);

        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }
};

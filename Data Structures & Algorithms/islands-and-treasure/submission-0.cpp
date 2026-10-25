class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // FIX 3 (safety): grid[0] is undefined behavior if the grid is empty.
        if (grid.empty() || grid[0].empty()) return;

        int R = grid.size();
        int C = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            // FIX 2: You wrote `for (int i = 0; i < q.size(); i++)`.
            // q.size() is re-checked on every pass while you pop and push,
            // so that loop doesn't cover exactly one BFS level.
            // Distances come from the parent (grid[r][c] + 1), so you don't
            // need level-by-level processing here. Pop one cell at a time.
            // (If you ever need levels, store the size first:
            //  int sz = q.size(); for (int i = 0; i < sz; i++) ...)
            auto [r, c] = q.front(); q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // FIX 1 (the crash): You checked r and c, which are always
                // in bounds, instead of the neighbor nr and nc.
                // So grid[nr][nc] was read with nr/nc = -1 or R/C,
                // outside the vector. Check the neighbor before reading it.
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
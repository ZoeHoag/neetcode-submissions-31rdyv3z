class Solution {
public:
    int scan(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || !grid[r][c]) return 0;
        grid[r][c] = 0;
        return 1 + scan(grid, r + 1, c) + scan(grid, r - 1, c) + scan(grid, r, c + 1) + scan(grid, r, c - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[r].size(); ++c) {
                if(grid[r][c]) {
                    res = max(res, scan(grid, r, c));
                }
            }
        }
        return res;
    }
};

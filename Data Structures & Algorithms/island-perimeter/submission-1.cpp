class Solution {
public:
    pair<int,int> getIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1) return {i,j};
            }
        }
        return {-1,-1};
    }
    vector<pair<int,int>> direct = {{0,1},{0,-1},{1,0},{-1,0}};

    int islandPerimeter(vector<vector<int>>& grid) {
        pair<int,int> cur = getIsland(grid);
        int res = 0;
        cout << cur.first << " " << cur.second << endl;
        stack<pair<int,int>> pending;
        pending.emplace(cur.first, cur.second);
        while(!pending.empty()) {
            pair<int,int> tmp = pending.top();
            pending.pop();
            if(grid[tmp.first][tmp.second] == 2) continue;
            grid[tmp.first][tmp.second] = 2;
            for(pair<int,int> &dir: direct) {
                int r = tmp.first + dir.first, c = tmp.second + dir.second;
                if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
                    if(grid[r][c] == 0) ++res;
                    else if(grid[r][c] == 1) pending.emplace(r, c); 
                } else ++res;
            }
        }
        return res;
    }
};
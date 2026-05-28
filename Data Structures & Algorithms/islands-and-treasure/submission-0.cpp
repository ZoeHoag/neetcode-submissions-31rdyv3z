class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int,int>> directs {{1,0},{-1,0},{0,1},{0,-1}};
        int c_size = grid[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pending;
        auto to2D = [](int c_size, int pos) {
            return make_pair(pos / c_size, pos % c_size);
        };
        auto to1D = [](int c_size, int r, int c) {
            return r * c_size + c;
        };
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 0) {
                    pending.emplace(0, to1D(c_size, r, c));
                }
            }
        }
        while(!pending.empty()) {
            pair<int,int> cur = pending.top();
            pending.pop();
            pair<int,int> pos = to2D(c_size, cur.second);
            if(grid[pos.first][pos.second] != cur.first) continue;
            for(pair<int,int> &d: directs) {
                pair<int,int> tmp = {pos.first + d.first, pos.second + d.second};
                if(
                    tmp.first < 0 || tmp.second < 0 || 
                    tmp.first >= grid.size() || tmp.second >= grid[0].size() || 
                    grid[tmp.first][tmp.second] == -1 || grid[tmp.first][tmp.second] <= cur.first + 1) continue;
                grid[tmp.first][tmp.second] = cur.first + 1;
                pending.emplace(cur.first + 1, to1D(c_size,tmp.first,tmp.second));
            }
        }
    }
};

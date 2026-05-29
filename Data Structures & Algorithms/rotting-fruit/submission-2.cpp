class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int c_size = grid[0].size();
        vector<pair<int,int>> directs{{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pending;
        auto to1D = [](int c_size, int r, int c) {
            return r * c_size + c;
        };
        auto to2D = [](int c_size, int pos) {
            return make_pair(pos / c_size, pos % c_size);
        };
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    grid[i][j] = 1;
                    pending.emplace(1, to1D(c_size, i, j));
                } else if(grid[i][j] == 1) grid[i][j] = INT_MAX;
            }
        }
        int res = 0;
        while(!pending.empty()) {
            pair<int,int> cur = pending.top();
            pending.pop();
            pair<int,int> pos = to2D(c_size, cur.second);
            if(cur.first != grid[pos.first][pos.second]) continue;
            res = cur.first - 1;
            cout << cur.first << endl;
            for(pair<int,int> &d: directs) {
                int r = d.first + pos.first;
                int c = d.second + pos.second;
            
                if(r < 0 || c < 0 || r >= grid.size() || c >= c_size || grid[r][c] == 0 || grid[r][c] < cur.first + 1) continue;
                grid[r][c] = cur.first + 1;
                pending.emplace(cur.first + 1, to1D(c_size, r, c));
            }
        }
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == INT_MAX) {
                    return -1;
                }
            }
        }
        
        return res;
    }
};

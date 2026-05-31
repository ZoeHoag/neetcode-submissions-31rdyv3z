class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int c_size = board[0].size();
        vector<pair<int,int>> directs{{1,0},{-1,0},{0,-1},{0,1}};
        vector<bool> store(board.size() * board[0].size() + 1, false);
        queue<int> pending;
        auto to1D = [](int c_size, int r, int c) {
            return c_size * r + c;
        };
        auto to2D = [](int c_size, int pos) {
            return make_pair(pos / c_size, pos % c_size);
        };
        for(int c = 0; c < board[0].size(); ++c) {
            if(board[0][c] == 'O') {
                pending.emplace(to1D(c_size, 0, c));
            }
            if(board[board.size() - 1][c] == 'O') {
                pending.emplace(to1D(c_size, board.size() - 1, c));
            }
        }

        for(int r = 0; r < board.size(); ++r) {
            if(board[r][0] == 'O') {
                pending.emplace(to1D(c_size, r, 0));
            }
            if(board[r][board[0].size() - 1] == 'O') {
                pending.emplace(to1D(c_size, r, board[0].size() - 1));
            }
        }
        while(!pending.empty()) {
            int cur = pending.front();
            pending.pop();
            if(store[cur]) continue;
            store[cur] = true;
            pair<int,int> pos = to2D(c_size, cur);
            for(pair<int,int> &d: directs) {
                int r = pos.first + d.first;
                int c = pos.second + d.second;
                if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == 'X' || store[to1D(c_size, r, c)]) continue;
                pending.emplace(to1D(c_size, r, c));
            }
        }
        for(int r = 0; r < board.size(); ++r) {
            for(int c = 0; c < board[0].size(); ++c) {
                board[r][c] = store[to1D(c_size, r, c)] ? 'O' : 'X';
            }
        }
    }
};

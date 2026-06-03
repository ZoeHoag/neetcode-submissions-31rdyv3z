class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> nums(numCourses, 0);
        unordered_map<int, vector<int>> store;
        for(vector<int> &p: prerequisites) {
            ++nums[p[0]];
            store[p[1]].push_back(p[0]);
        }
        queue<int> pending;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            if(!nums[i]) pending.emplace(i);
        }
        while(!pending.empty()) {
            int cur = pending.front();
            pending.pop();
            res.push_back(cur);
            for(int &pos: store[cur]) {
                if(--nums[pos] == 0) pending.emplace(pos);
            }
        }
        return (res.size() == numCourses) ? res : vector<int>{};
    }
};

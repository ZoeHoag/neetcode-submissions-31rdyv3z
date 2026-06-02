class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> count(numCourses, 0);
        unordered_map<int, vector<int>> store;
        for(vector<int> &p: prerequisites) {
            ++count[p[0]];
            store[p[1]].push_back(p[0]);
        }
        queue<int> pending;
        for(int i = 0; i < numCourses; ++i) {
            if(count[i] == 0) {
                pending.emplace(i);
            }
        }
        while(!pending.empty()) {
            int cur = pending.front();
            pending.pop();
            --numCourses;
            for(int &s: store[cur]) {
                if(--count[s] == 0) {
                    pending.emplace(s);
                }
            }
        }
        return numCourses == 0;
    }
};

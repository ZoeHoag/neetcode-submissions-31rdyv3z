class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> pre(numCourses, 0);
        unordered_map<int, vector<int>> store;
        for(vector<int> &p: prerequisites) {
            ++pre[p[1]];
            store[p[0]].push_back(p[1]);
        }
        queue<int> pending;
        for(int i = 0; i < numCourses; ++i) {
            if(pre[i] == 0) pending.emplace(i);
        }
        vector<unordered_set<int>> havePre;
        havePre.resize(numCourses);
        while(!pending.empty()) {
            int cur = pending.front();
            pending.pop();
            for(int &d: store[cur]) {
                havePre[d].insert(cur);
                havePre[d].insert(havePre[cur].begin(), havePre[cur].end());
                if(--pre[d] == 0) {
                    pending.emplace(d);
                }
            }
        }
        vector<bool> res(queries.size(), false);
        for(int i = 0; i < queries.size(); ++i) {
            cout << queries[i][0] << " || " << havePre[queries[i][1]].contains(queries[i][0]) << endl;
            res[i] = havePre[queries[i][1]].contains(queries[i][0]);
        }
        return res;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<queue<int>> start(s.size()), end(s.size());
        for(int j = 0; j < wordDict.size(); ++j) {
            if(wordDict[j] == s) return true;
            for(int i = 0; i <= int(s.size() - wordDict[j].size()); ++i) {
                string sub = s.substr(i, wordDict[j].size());
                if(sub == wordDict[j]) {
                    start[i].emplace(j);
                    end[i + wordDict[j].size() - 1].emplace(j);
                }
            }
        }
        unordered_set<string> store;
        bool isEndPre = true;
        for(int i = 0; i < s.size(); ++i) {
            while(!start[i].empty() && isEndPre) {
                int pos = start[i].front();
                string key = to_string(pos) + "_" + to_string(i + wordDict[pos].size() - 1);
                store.insert(key);
                start[i].pop();
            }
            isEndPre = false;
            while(!end[i].empty()) {
                int pos = end[i].front();
                string key = to_string(pos) + "_" + to_string(i);
                if(store.find(key) != store.end()) {
                    if(!isEndPre) isEndPre = true;
                    store.erase(key);
                }
                end[i].pop();
            }
        }
        return isEndPre;
    }
};

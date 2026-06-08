class Solution {
public:
    vector<int> p;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        p.resize(edges.size() + 1);
        for(int i = 1; i < p.size(); ++i) p[i] = i;
        
        for(vector<int> &e: edges) {
            int pv = find(e[0]), pu = find(e[1]);
            if(pv == pu) {
                return e;
            } else {
                if(pv >= pu) {
                    p[pv] = pu;
                } else p[pu] = pv;
            }
        }
        return {};
    }

    int find(int n) {
        if(p[n] != n) {
            p[n] = find(p[n]);
        }
        return p[n];
    }
};

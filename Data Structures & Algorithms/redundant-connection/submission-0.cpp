struct UJ {
    vector<int> p, s;
    UJ(int n) {
        p.resize(n);
        s.resize(n);
        for(int i = 0; i < n; ++i) {
            p[i] = i;
            s[i] = 1;
        }
    }
    int find(int n) {
        if(p[n] != n) {
            p[n] = find(p[n]);
        }
        return p[n];
    }

    bool join(int u, int v) {
        int pv = find(v), pu = find(u);
        if(pv == pu) return true;
        if(s[pv] > s[pu]) swap(pv, pu);
        s[pu] += s[pv];
        p[pv] = pu;
        return false; 
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UJ *uj = new UJ(edges.size() + 1);
        for(vector<int> &e: edges) {
            if(uj->join(e[0],e[1])) {
                return e;
            }
        }
        return {};
    }
};

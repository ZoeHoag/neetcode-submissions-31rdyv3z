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
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        if(s[pv] > s[pu]) swap(pu, pv);
        s[pu] += s[pv];
        p[pv] = pu;
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;
        UJ *uj = new UJ(res);
        for(vector<int> &e: edges) {
            if(uj->join(e[0], e[1])) {
                --res;
            }
        }
        return res;
    }
};

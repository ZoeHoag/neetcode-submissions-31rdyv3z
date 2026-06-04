struct UnionJoin{
    vector<int> parent, size;
    int node;
    UnionJoin(int n) {
        node = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int node) {
        if(parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    bool unionNodes(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        --node;
        if(size[pv] > size[pu]) {
            swap(pu, pv);
        }
        size[pu] += size[pv];
        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n - 1) return false;
        UnionJoin *uj = new UnionJoin(n);
        for(vector<int> &e: edges) {
            if(!uj->unionNodes(e[0],e[1])) {
                return false;
            }
        }
        return uj->node == 1;
    }
};

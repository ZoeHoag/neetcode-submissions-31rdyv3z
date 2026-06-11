class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> keyToId;
        vector<vector<double>> table(40, vector<double>(40,-1.0));
        int size = 0;
        for(int i = 0; i < equations.size(); ++i) {
            if(!keyToId.contains(equations[i][0])) {
                cout << equations[i][0] << " -> " << size << endl;
                keyToId[equations[i][0]] = size++;
                table[keyToId[equations[i][0]]][keyToId[equations[i][0]]] = 1.0;
            }
            if(!keyToId.contains(equations[i][1])) {
                cout << equations[i][1] << " -> " << size << endl;
                keyToId[equations[i][1]] = size++;
                table[keyToId[equations[i][1]]][keyToId[equations[i][1]]] = 1.0;
            }
            table[keyToId[equations[i][0]]][keyToId[equations[i][1]]] = values[i];
            table[keyToId[equations[i][1]]][keyToId[equations[i][0]]] = 1.0/values[i];
        }

        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                for(int k = 0; k < size; ++k) {
                    cout << j << "/" << k << " => " << i << endl;
                    if(table[j][k] == -1 && table[j][i] != -1 && table[i][k] != -1) {
                        table[j][k] = table[j][i] * table[i][k];
                        table[k][j] = 1.0/table[j][k];
                    }
                }
            }
        }
        vector<double> res(queries.size(), -1);
        for(int i = 0; i < queries.size(); ++i) {
            if (!keyToId.contains(queries[i][0]) || !keyToId.contains(queries[i][1])) continue;
            res[i] = table[keyToId[queries[i][0]]][keyToId[queries[i][1]]];
        }
        return res;

    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = 0;
        string res;
        while(true) {
            char tmp = strs[0][pos];
            for(string& str: strs) {
                if(pos >= str.size() || str[pos] != tmp) {
                    return res;
                }
            }
            ++pos;
            res += tmp;
        }
        return res;
    }
};
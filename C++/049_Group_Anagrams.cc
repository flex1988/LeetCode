class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ret;

        for (auto& x : strs) {
            string tmp(x);
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(x);
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            ret.push_back(it->second);
        }

        return ret;
    }
};

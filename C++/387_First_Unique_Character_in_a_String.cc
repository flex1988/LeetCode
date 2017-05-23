class Solution {
   public:
    int firstUniqChar(string s) {
        vector<int> ret(26);
        int i;
        for (i = 0; i < s.length(); i++) {
            ret[s.at(i) - 'a']++;
        }

        for (i = 0; i < s.length(); i++) {
            if (ret[s.at(i) - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

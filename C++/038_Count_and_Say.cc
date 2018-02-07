class Solution {
   public:
    string countAndSay(int n) {
        if (n == 0)
            return "";

        string ret = "1";
        while (--n) {
            string tmp = "";

            for (int i = 0; i < ret.size(); i++) {
                int count = 1;
                while (i + 1 < ret.size() && ret[i] == ret[i + 1]) {
                    count++;
                    i++;
                }
                tmp += to_string(count) + ret[i];
            }
            ret = tmp;
        }

        return ret;
    }
};

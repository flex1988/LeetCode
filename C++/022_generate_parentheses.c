class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;

        process(ret, "", n, 0);

        return ret;
    }

    void process(vector<string> &ret, string s, int m, int n) {
        if (m == 0 && n == 0) {
            ret.push_back(s);
            return;
        }

        if (m > 0) {
            process(ret, s + "(", m - 1, n + 1);
        }

        if (n > 0) {
            process(ret, s + ")", m, n - 1);
        }
    }
};

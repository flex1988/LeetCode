class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int len_s = s.size();
        int sum_s = 0;
        for (int i = 0; i < len_s; i++)
            sum_s += s[i];

        int len_t = t.size();
        int sum_t = 0;
        for (int i = 0; i < len_t; i++)
            sum_t += t[i];
        return sum_t - sum_s;
    }
};

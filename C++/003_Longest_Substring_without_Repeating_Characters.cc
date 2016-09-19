class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int* dict = (int*)calloc(256, sizeof(int));
        memset(dict, -0x1, 256 * sizeof(int));
        int ret = 0;
        int start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (dict[s.at(i)] > start) start = dict[s.at(i)];
            dict[s.at(i)] = i;
            ret = max(ret, i - start);
        }
        return ret;
    }
};

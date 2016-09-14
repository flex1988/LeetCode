class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ret = nums[0];
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end();
             it++) {
            ret ^= *it;
        }
        return ret;
    }
};

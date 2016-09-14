class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (nums.size() == 0) return 0;
        size_t size = nums.size();
        int j = size - 1;
        for (int i = 0; i < j;) {
            while (i < size && nums[i] != val)
                i++;
            while (j > 0 && nums[j] == val)
                j--;
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        while (j < size && nums[j] != val)
            j++;
        nums.erase(nums.begin() + j, nums.end());
        return nums.size();
    }
};

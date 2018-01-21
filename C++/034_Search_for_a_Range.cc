class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return vector<int>(2, -1);
        if (nums.size() == 1)
            return nums[0] == target ? vector<int>(2, 0) : vector<int>(2, -1);
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] > target) {
                high--;
            } else if (nums[mid] < target) {
                low++;
            } else {
                vector<int> ret;
                int r1 = mid;
                int r2 = mid;

                while (nums[r1 - 1] == target && r1 > 0) r1--;
                while (nums[r2 + 1] == target && r2 < nums.size() - 1) r2++;

                ret.push_back(r1);
                ret.push_back(r2);
                return ret;
            }
        }

        return nums[low] == target ? vector<int>(2, low) : vector<int>(2, -1);
    }
};

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4)
            return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            int one = nums[i];
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int two = nums[j];

                int low = j + 1;
                int high = nums.size() - 1;
                int innertarget = target - one - two;

                while (low < high) {
                    if (nums[low] + nums[high] > innertarget) {
                        high--;
                    } else if (nums[low] + nums[high] < innertarget) {
                        low++;
                    } else {
                        result.push_back(vector<int>{one, two, nums[low], nums[high]});
                        while (nums[low] == nums[low + 1]) low++;
                        while (nums[high] == nums[high - 1]) high--;
                        high--;
                    }
                }
                while (nums[j] == nums[j + 1]) j++;
            }
            while (nums[i] == nums[i + 1]) i++;
        }

        return result;
    }
};

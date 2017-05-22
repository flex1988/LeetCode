class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        int sum;
        while (low < high) {
            sum = numbers[low] + numbers[high];
            if (sum == target) {
                return vector<int>{low + 1, high + 1};
            } else if (sum > target) {
                high--;
            } else {
                low++;
            }
        }
    }
};

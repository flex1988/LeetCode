class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int oi = nums.size();
        int oj = (*nums.begin()).size();

        if (r * c != oi * oj || r == nums.size())
            return nums;

        int i, j;
        vector<vector<int>> matrix;

        for (i = 0; i < r; i++) {
            vector<int> row;
            for (j = 0; j < c; j++) {
                int idx = i * c + j;
                row.push_back(nums[idx / oj][idx % oj]);
            }
            matrix.push_back(row);
        }

        return matrix;
    }
};

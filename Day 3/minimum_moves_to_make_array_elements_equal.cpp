class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // find the median
        int median, i, res = 0;
        if (nums.size() % 2 == 1) {
            median = nums[nums.size() / 2];
        } else {
            median = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
        }

        for (i = 0; i < nums.size(); i++) {
            res += abs(nums[i] - median);
        }

        return res;
    }
};

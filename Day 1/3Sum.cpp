class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int i, left, right;
        sort(nums.begin(), nums.end());
        for (i = 0; i <= nums.size() - 3; i++) {
            // use two pointers from i+1 and nums.size()-1
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    st.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        // create a result vector from the set..
        vector<vector<int>> res;
        for (auto it : st) {
            res.push_back({it[0], it[1], it[2]});
        }
        return res;
    }
};

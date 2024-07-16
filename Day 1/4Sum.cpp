class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        // using two loops, within which two pointer approach is followed..

        // using a set as it will not store any duplicates
        set<vector<int>> st;
        int i, j, left, right;
        for (i = 0; i <= nums.size() - 4; i++) {
            for (j = i + 1; j <= nums.size()- 3; j++) {
                left = j + 1;
                right = nums.size() - 1;
                while (left < right) {
                    //answer may lead to integer overflow,using static_cast
                    long long sum = static_cast<long long>(nums[i])+ nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        st.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    } else if (sum > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        // create the result array using set
        vector<vector<int>> res;
        for (auto it : st) {
            res.push_back({it[0], it[1], it[2], it[3]});
        }
        return res;
    }
};

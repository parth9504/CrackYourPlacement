class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, index = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        for (i = index; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cz = 0, co = 0, ct = 0, i;
        // count the number of 0's 1's 2's
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cz++;
            } else if (nums[i] == 1) {
                co++;
            } else {
                ct++;
            }
        }

        // overwrite the array such that all 1's , then 2's and 0's are present
        i = 0;
        while (cz > 0) {
            nums[i++] = 0;
            cz--;
        }
        while (co > 0) {
            nums[i++] = 1;
            co--;
        }
        while (ct > 0) {
            nums[i++] = 2;
            ct--;
        }
    }
};

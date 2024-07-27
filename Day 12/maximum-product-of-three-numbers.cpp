class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //sort the array
        sort(nums.begin(),nums.end());
        //store the first three max numbers..
        int a=nums[nums.size()-1];
        int b=nums[nums.size()-2];
        int c=nums[nums.size()-3];
        int prod1=a*b*c;
        //check the first two smallest elements
        int d=nums[0];
        int e=nums[1];
        int prod2=d*e*a;
        return max(prod1,prod2);}};
  
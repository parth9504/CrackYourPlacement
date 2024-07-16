class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        int i;
        for(i=0;i<nums.size();i++){
            mp[nums[i]]=1;}
        int res=mp.size();
        i=0;
        for(auto it:mp){
            nums[i++]=it.first;}
            return res;}};
        
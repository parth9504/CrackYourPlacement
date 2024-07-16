class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});}
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a.first<b.first;});
        int left=0,right=nums.size()-1;
        while(left<right){
            if((v[left].first+v[right].first)==target){
                break;}
            else if((v[left].first+v[right].first)>target){
                right--;}
            else{
                left++;}}
        return {v[left].second,v[right].second};}};
          
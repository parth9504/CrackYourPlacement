class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i;
        for(i=0;i<nums.size();i++){
            mp[nums[i]]++;}
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.first,it.second});}
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a.second>b.second;});

        vector<int>res;
        for(i=0;i<k;i++){
            res.push_back(v[i].first);}
            return res;}};

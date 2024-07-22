class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       long long int prod=1;
       int i,cz=0;
       for(i=0;i<n;i++){
           if(nums[i]==0){
               cz++;}
           else{
           prod*=nums[i];}}
        vector<long long int>res(n);
        for(i=0;i<n;i++){
            if(nums[i]!=0){
            if(cz>=1){
                res[i]=0;}
            else{
                res[i]=prod/nums[i];}}
            else if(nums[i]==0){
                if(cz>1){
                    res[i]=0;}
                else{
                res[i]=prod;}}}
        return res;}};
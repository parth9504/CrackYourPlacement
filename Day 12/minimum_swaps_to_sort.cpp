class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int>temp=nums;
	    sort(temp.begin(),temp.end());
	    //store the indices for eements in the sorted array
	    unordered_map<int,int>mp;
	    int i,count=0;
	    for(i=0;i<temp.size();i++){
	        mp[temp[i]]=i;}
	    for(i=0;i<nums.size();){
	        if(mp[nums[i]]!=i){
	            swap(nums[i],nums[mp[nums[i]]]);
	            count++;}
	       else{
	           i++;}}
	      return count;}};
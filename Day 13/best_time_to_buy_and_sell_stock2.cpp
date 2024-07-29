class Solution {
public:
//buying allowed buy value=1 otherwise not
    int find(int ind,int buy,vector<vector<int>>&dp,vector<int>& prices){
        //base case
        if(ind==prices.size()){
            return 0;}
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];}
        
        //buy or not buy..
        int profit=0;
        if(buy==1){
            //if buying, add negative value for the profit..
            profit=max(-prices[ind]+find(ind+1,0,dp,prices), 0+find(ind+1,1,dp,prices));}
        else{
            //if selling, add the positive value for profit
            profit=max(prices[ind]+find(ind+1,1,dp,prices),0+find(ind+1,0,dp,prices));}
        
        return dp[ind][buy]=profit;}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(0,1,dp,prices);}};
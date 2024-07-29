class Solution {
public:
    int find(int ind,int buy,int f, vector<vector<vector<int>>>dp,vector<int>& prices){
        if(ind==prices.size()||f==0){
            return 0;}
        if(dp[ind][buy][f]!=-1){
            return dp[ind][buy][f];}
        int profit=0;
        if(buy==1){
            profit=max(-prices[ind]+find(ind+1,0,f,dp,prices),0+find(ind+1,1,f,dp,prices));}
        else{
            profit=max(prices[ind]+find(ind+1,1,f-1,dp,prices),0+find(ind+1,0,f,dp,prices));}
        return dp[ind][buy][f]=profit;}


    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        int ind,buy,f;
        for(ind=prices.size()-1;ind>=0;ind--){
            for(buy=0;buy<=1;buy++){
                for(f=1;f<=2;f++){
                    if(buy==1){
                        dp[ind][buy][f]=max(-prices[ind]+dp[ind+1][0][f], 0+dp[ind+1][1][f]);}
                    else{
                        dp[ind][buy][f]=max(prices[ind]+dp[ind+1][1][f-1], 0+dp[ind+1][0][f]);}}}}
        
        return dp[0][1][2];}};
                   
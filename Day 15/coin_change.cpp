class Solution {
public:
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            if(coins[ind]>0){
                if(amount%coins[ind]==0) 
                return amount/coins[ind];
                else
                return 1e9;}}
        if (dp[ind][amount] !=-1) return dp[ind][amount];
        int notTake = 0+ f(ind - 1, amount, coins, dp);
        int take =1e9;
        if (coins[ind] <= amount) {
            take = 1 + f(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = min(take, notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = f(n - 1, amount, coins, dp);
        return res<1e9? res : -1;
    }
};
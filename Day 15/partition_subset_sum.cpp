class Solution{
public:
    bool f(int ind,int sum,int arr[],vector<vector<int>>&dp){
        if(sum==0){
            return true;}
        if(ind==0){
            return arr[ind]==sum;}
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];}
        bool not_take=f(ind-1,sum,arr,dp);
        bool take=false;
        if(arr[ind]<=sum){
            take=f(ind-1,sum-arr[ind],arr,dp);}
        return dp[ind][sum]=take||not_take;}
    int equalPartition(int N, int arr[])
    {
        //find the sum of the array elements
        int sum=0,i,j;
        for(i=0;i<N;i++){
            sum+=arr[i];}
        //if sum is odd,partition is not possible
        if(sum%2==1){
            return 0;}
        sum=sum/2;
       // cout<<sum;
        vector<vector<int>>dp(N,vector<int>(sum+1,-1));
        bool k= f(N-1,sum,arr,dp);
        return dp[N-1][sum]==true?1:0;}};
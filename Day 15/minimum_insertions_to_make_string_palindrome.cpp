class Solution {
public:
    int minInsertions(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        //find the longest palindromic subsequence..
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1));
        int n=s.length(),i,j;
        for(i=0;i<=n;i++){
            dp[0][i]=0;}
        for(i=0;i<=n;i++){
            dp[i][0]=0;}
        
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(s[i-1]==temp[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                   }
                else{
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);}}}
        return n-dp[n][n];}};
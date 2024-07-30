class Solution {
  public:

    int longestCommonSubstr(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        //set the first row and first column to
        int i,j,maxi=0;
        for(i=0;i<=m;i++){
            dp[0][i]=0;}
        for(i=0;i<=n;i++){
            dp[i][0]=0;}
        
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxi=max(maxi,dp[i][j]);}
                else{
                    dp[i][j]=0;}}}
        return maxi;}};
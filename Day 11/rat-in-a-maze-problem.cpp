class Solution {
  public:
    vector<pair<int,int>>v={{-1,0},{1,0},{0,-1},{0,1}};
    vector<char>directions={'U','D','L','R'};
    void dfs(int r,int c,vector<vector<int>>&mat,vector<vector<int>>&visited,
    vector<string>&res,string temp){
        if(r==mat.size()-1 && c==mat.size()-1){
            res.push_back(temp);
            return;}
        for(int i=0;i<4;i++){
            int new_row=r+v[i].first;
            int new_col=c+v[i].second;
            if(new_row>=0 && new_row<mat.size() && new_col>=0 &&
            new_col<mat.size() && visited[new_row][new_col]==-1 
            && mat[new_row][new_col]==1){
                visited[new_row][new_col]=1;
                    dfs(new_row,new_col,mat,visited,res,temp+directions[i]);
                    //mp.pop_back();
                 visited[new_row][new_col]=-1;
            }}}
                    
    vector<string> findPath(vector<vector<int>> &mat) {
        int n=mat.size();
        if(mat[0][0]==0||mat[n-1][n-1]==0){
            return {};}
        vector<vector<int>>visited(n,vector<int>(n,-1));
        int i,j;
        vector<string>res;
        string k="";
        visited[0][0]=1;
        dfs(0,0,mat,visited,res,k);
        return res;}};
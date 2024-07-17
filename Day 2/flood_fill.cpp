class Solution {
public:
    vector<pair<int,int>>v={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int sr,int sc,vector<vector<int>>&image,int val,int color){
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int new_row=sr+v[i].first;
            int new_col=sc+v[i].second;
            if(new_row>=0 && new_row<image.size() && new_col>=0 && 
            new_col<image[0].size() && image[new_row][new_col]==val){
                dfs(new_row,new_col,image,val,color);}}}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val=image[sr][sc];
        if(val!=color){
        dfs(sr,sc,image,val,color);}
        return image;
    }
};
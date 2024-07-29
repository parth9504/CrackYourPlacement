class Solution {
public:
    vector<pair<int,int>>v={{0,1},{0,-1},{1,0},{1,1},{-1,0},{-1,1},{-1,-1},{1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>temp(m,vector<int>(n));
        int i,j,k;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                int live=0;
                for(k=0;k<8;k++){
                    int new_row=v[k].first+i;
                    int new_col=v[k].second+j;
                    if(new_row>=0 && new_row<m && new_col>=0 && new_col<n){
                        if(board[new_row][new_col]==1){
                            live++;}}}
                if(board[i][j]==0 && live==3){
                    temp[i][j]=1;}
                else if(board[i][j]==1 && live<2){
                    temp[i][j]=0;}
                else if(board[i][j]==1 && (live==2||live==3)){
                    temp[i][j]=1;}
                else if(board[i][j]==1 && live>3){
                    temp[i][j]=0;}}}
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                board[i][j]=temp[i][j];}}}};
            
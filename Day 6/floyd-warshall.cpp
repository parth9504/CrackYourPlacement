class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int i,j,k,n=matrix.size();
	    //convert -1 to some higher value
	    for(i=0;i<n;i++){
	        for(j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;}}}
	   
	   //using floyd warshall
	   for(k=0;k<n;k++){
	       for(i=0;i<n;i++){
	           for(j=0;j<n;j++){
	               matrix[i][j]=min(matrix[i][j],(matrix[i][k]+matrix[k][j]));}}}
	   for(i=0;i<n;i++){
	       for(j=0;j<n;j++){
	           if(matrix[i][j]==1e9){
	               matrix[i][j]=-1;}}}
	}};
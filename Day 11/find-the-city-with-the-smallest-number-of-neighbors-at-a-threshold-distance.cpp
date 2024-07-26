class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        //use floyd warshall algorithm..
        vector<vector<int>>v(n,vector<int>(n,-1));
        int i,j,k;
        //firstly fill the matrix with values..
        for(auto it:edges){
            v[it[0]][it[1]]=it[2];
            v[it[1]][it[0]]=it[2];}
        for ( i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (v[i][j] == -1) {
					v[i][j] = 1e9;
				}
				if (i == j) v[i][j] = 0;
			}
		}
        
        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    v[i][j]=min(v[i][j],v[i][k]+v[k][j]);}}}
        
        for ( i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (v[i][j] == 1e9) {
					v[i][j] = -1;}}}
        
        /*if there are more than one city having same values we
         need to return the city having higher val*/
        int mini=INT_MAX;
        int ele=-1;
        for(i=n-1;i>=0;i--){
            int count=0;
            for(j=0;j<n;j++){
                if(v[i][j]<=thresh){
                    count++;}}
            if(count<mini){
                mini=count;
                ele=i;}}
        return ele;}};
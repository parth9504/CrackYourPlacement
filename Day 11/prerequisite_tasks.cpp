class Solution {
public:
    bool dfs(int src,vector<vector<int>>&adj, vector<int>&visited,
    vector<int>&temp){
        visited[src]=1;
        temp[src]=1;
        for(auto it:adj[src]){
            if(visited[it]==-1){
                if(dfs(it,adj,visited,temp)==true){
                    return true;}}
            else if(temp[it]==1)    //not visited but already marked in stack
            {
                return true;}}
        temp[src]=0;
        return false;}
	bool isPossible(int N,int P, vector<pair<int, int> >&v) {
	    vector<vector<int>>adj(N);
	    int i;
	    for(auto it:v){
	        adj[it.second].push_back(it.first);}
	    vector<int>visited(N,-1);
	    vector<int>temp(N,0);
	    for(i=0;i<N;i++){
	        //check if cycle is present
	        if(dfs(i,adj,visited,temp)==true){
	            return false;}}
	   return true;}};
	   
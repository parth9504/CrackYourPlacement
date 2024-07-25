class Solution {
public:
	bool dfs(int src,vector<int>adj[],vector<int>&visited,vector<int>&color) {
		visited[src]=1;
		if(color[src]==-1) {
			color[src]=0;
		}
		for(auto it:adj[src]) {
			if(visited[it]==-1) {
				color[it]=!color[src];
				if(dfs(it,adj,visited,color)==false) {
					return false;
				}
			}
			else {
				if(visited[it]==1 && color[it]==color[src]) {
					return false;
				}
			}
		}
		return true;
	}
	bool isBipartite(int V, vector<int>adj[]) {
		vector<int>visited(V,-1);
		vector<int>color(V,-1);

		int i;
		for(i=0; i<V; i++) {
			if(visited[i]==-1) {
				if(dfs(i,adj,visited,color)==false) {
					return false;
				}
			}
		}
		return true;
	}
};
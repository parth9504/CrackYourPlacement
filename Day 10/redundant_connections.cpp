class Solution {
public:
	void dfs(int src,vector<vector<int>>&adj,vector<int>&visited) {
		visited[src]=1;
		for(auto it:adj[src]) {
			if(visited[it]== -1) {
				dfs(it,adj,visited);
			}
		}
	}
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		//make graph by excluding one edhge and check if it results in all nodes being visited..
		int k=0,i,j;
		for(i=edges.size()-1; i>=0; i--) {
			vector<vector<int>>adj(edges.size()+1);
			for(j=0; j<edges.size(); j++) {
				if(i!=j) {
					adj[edges[j][0]].push_back(edges[j][1]);
					adj[edges[j][1]].push_back(edges[j][0]);
				}
			}
			vector<int>visited(edges.size()+1,-1);
			dfs(1,adj,visited);
			int f=0;
			//check if all nodes have been visited
			for(int k=1; k<=edges.size(); k++) {
				if(visited[k]==-1) {
					f=1;
					break;
				}
			}
			if(f==0) {
				return {edges[i][0],edges[i][1]};
			}
		}
		return {};
	}
};

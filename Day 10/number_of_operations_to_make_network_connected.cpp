class Solution {
public:
	void dfs(int src,vector<vector<int>>&adj,vector<int>&visited) {
		visited[src]=1;
		for(auto it:adj[src]) {
			if(visited[it]==0) {
				dfs(it,adj,visited);
			}
		}
	}
	int makeConnected(int n, vector<vector<int>>&v) {
		//to make the connections at least n-1 connections should exist.
		if(v.size()<n-1) {
			return -1;
		}
		//make adjacency list
		vector<vector<int>>adj(n);
		for(int i=0; i<v.size(); i++) {
			adj[v[i][0]].push_back(v[i][1]);
			adj[v[i][1]].push_back(v[i][0]);
		}

		//now find the disconnected components..

		vector<int>visited(n,0);
		int i,j,count=0;
		for(i=0; i<n; i++) {
			if(visited[i]==0) {
				count++;
				dfs(i,adj,visited);
			}
		}
		return count-1;
	}
};
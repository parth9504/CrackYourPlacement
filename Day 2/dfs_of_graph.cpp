class Solution
{
public:
  void dfs (int src, vector < int >adj[], vector < int >&visited,
			vector < int >&res)
  {
	visited[src] = 1;
	res.push_back (src);
	for (auto it:adj[src])
	  {
		if (visited[it] == -1)
		  {
			dfs (it, adj, visited, res);
		  }
	  }
  }
  // Function to return a list containing the DFS traversal of the graph.
  vector < int >dfsOfGraph (int V, vector < int >adj[])
  {
	vector < int >visited (V, -1);
	vector < int >res;
	for (int i = 0; i < V; i++)
	  {
		if (visited[i] == -1)
		  {
			dfs (i, adj, visited, res);
		  }
	  }
	return res;
  }
};

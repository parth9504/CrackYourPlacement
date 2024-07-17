class Solution
{
public:
  void bfs (int src, vector < int >adj[], vector < int >&visited,
			vector < int >&res)
  {
	visited[src] = 1;
	queue < int >q;
	  q.push (src);
	while (!q.empty ())
	  {
		int node = q.front ();
		  q.pop ();
		  res.push_back (node);
		//iterate over adj[node]
		for (auto it:adj[node])
		  {
			if (visited[it] == -1)
			  {
				visited[it] = 1;
				q.push (it);
			  }
		  }
	  }
  }
  // Function to return Breadth First Traversal of given graph.
  vector < int >bfsOfGraph (int V, vector < int >adj[])
  {
	vector < int >res;
	vector < int >visited (V, -1);
	bfs (0, adj, visited, res);
	return res;
  }
};

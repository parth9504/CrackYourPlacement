class Solution
{
public:
  void dfs (int src, vector < int >adj[], vector < int >&visited,
			stack < int >&st)
  {
	visited[src] = 1;
	for (auto it:adj[src])
	  {
		if (visited[it] == -1)
		  {
			dfs (it, adj, visited, st);
		  }
	  }
	st.push (src);
  }
  //Function to return list containing vertices in Topological order. 
  vector < int >topoSort (int V, vector < int >adj[])
  {
	vector < int >visited (V, -1);
	stack < int >st;
	for (int i = 0; i < V; i++)
	  {
		if (visited[i] == -1)
		  {
			dfs (i, adj, visited, st);
		  }
	  }


	//push the stack elements in the result array
	vector < int >res;
	while (!st.empty ())
	  {
		res.push_back (st.top ());
		st.pop ();
	  }
	return res;
  }
};

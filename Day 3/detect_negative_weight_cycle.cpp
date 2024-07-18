class Solution
{
public:
  int isNegativeWeightCycle (int n, vector < vector < int >>edges)
  {
	int i;
	  vector < int >dist (n, 1e9);
	  dist[0] = 0;
	//using bellman ford, do relaxation till V-1
	for (i = 0; i < n - 1; i++)
	  {
	  for (auto it:edges)
		  {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (wt + dist[u] < dist[v])
			  {
				dist[v] = wt + dist[u];
			  }
		  }
	  }

	//check now for negative cycle..
	for (auto it:edges)
	  {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (wt + dist[u] < dist[v])
		  {
			return 1;
		  }
	  }
	return 0;
  }
};

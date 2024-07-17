class Solution
{
public:
  vector < pair < int, int >>v = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

  void dfs (int r, int c, vector < vector < char >>&grid,
			vector < vector < int >>&visited)
  {
	visited[r][c] = 1;
	//convert the 'O' to '#'
	grid[r][c] = '#';

	for (int i = 0; i < 4; i++)
	  {
		int new_row = r + v[i].first;
		int new_col = c + v[i].second;

		//check for boundary
		if (new_row >= 0 && new_row < grid.size () && new_col >= 0
			&& new_col < grid[0].size () && visited[new_row][new_col] == -1
			&& grid[new_row][new_col] == 'O')
		  {
			dfs (new_row, new_col, grid, visited);
		  }
	  }
  }
  vector < vector < char >>fill (int m, int n, vector < vector < char >>grid)
  {
	/*using dfs to convert all the O's which 
	   are not surrounded by 'X' to some other character */

	int i, j;
	vector < vector < int >>visited (m, vector < int >(n, -1));
	for (i = 0; i < m; i++)
	  {
		for (j = 0; j < n; j++)
		  {
			if ((i == 0 || j == 0 || i == m - 1 || j == n - 1)
				&& grid[i][j] == 'O' && visited[i][j] == -1)
			  {
				dfs (i, j, grid, visited);
			  }
		  }
	  }

	//convert all the remaining O's to X 
	for (i = 0; i < m; i++)
	  {
		for (j = 0; j < n; j++)
		  {
			if (grid[i][j] == 'O')
			  {
				grid[i][j] = 'X';
			  }
			else if (grid[i][j] == '#')
			  {
				grid[i][j] = 'O';
			  }
		  }
	  }

	return grid;
  }
};

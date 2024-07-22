class Solution
{
public:
  //Function to find if there is a celebrity in the party or not.
  int celebrity (vector < vector < int > >&m, int n)
  {
	vector < int >know_others (n, 0);
	  vector < int >know_them (n, 0);
	int i, j;
	for (i = 0; i < n; i++)
	  {
		for (j = 0; j < n; j++)
		  {
			if (m[i][j] == 1)
			  {
				know_others[i]++;
				know_them[j]++;
			  }
		  }
	  }
	for (i = 0; i < n; i++)
	  {
		if (know_them[i] == n - 1 && know_others[i] == 0)
		  {
			return i;
		  }
	  }
	return -1;
  }
};

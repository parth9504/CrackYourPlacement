class Solution
{
public:
  int findPair (int n, int x, vector < int >&arr)
  {
	int i, j, count = 0;
	for (i = 0; i < n; i++)
	  {
		for (j = i + 1; j < n; j++)
		  {
			if (abs (arr[i] - arr[j]) == x)
			  {
				return 1;
			  }
		  }
	  }
	return -1;
  }
};

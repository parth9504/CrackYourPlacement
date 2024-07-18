class Solution
{
public:
  //Function to find the smallest positive number missing from the array.
  int missingNumber (int arr[], int n)
  {
	int i;
	  vector < int >v;
	for (i = 0; i < n; i++)
	  {
		v.push_back (arr[i]);
	  }
	sort (v.begin (), v.end ());
	//find the first positive element..
	for (i = 0; i < n; i++)
	  {
		if (v[i] > 0)
		  {
			break;
		  }
	  }
	if (v[i] > 1 || i == n)
	  {
		return 1;
	  }
	int ele = 1, k, j;
	//ignore all 1's
	while (v[i] == 1)
	  {
		i++;
	  }
	for (j = i; j < n;)
	  {
		if (v[j] != ele + 1)
		  {
			return ele + 1;
		  }
		//for duplicates..
		for (k = j + 1; k < n; k++)
		  {
			if (v[k] != v[j])
			  {
				break;
			  }
		  }
		ele = v[j];
		j = k;
	  }

	return v[n - 1] + 1;
  }
};

class Solution
{
public:
  vector < vector < int >>uniquePerms (vector < int >&arr, int n)
  {
	sort (arr.begin (), arr.end ());
	vector < vector < int >>res;
	do
	  {
		res.push_back (arr);
	  }
	while (next_permutation (arr.begin (), arr.end ()));
	return res;
  }
};

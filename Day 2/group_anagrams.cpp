class Solution
{
public:
  vector < int >find_freq (string a)
  {
	vector < int >freq (26, 0);
	int i;
	for (i = 0; i < a.length (); i++)
	  {
		freq[a[i] - 97]++;
	  }
	return freq;
  }

  vector < vector < string >> groupAnagrams (vector < string > &strs)
  {
	int i, j;

	vector < vector < int >>freq;
	for (i = 0; i < strs.size (); i++)
	  {
		freq.push_back (find_freq (strs[i]));
	  }

	vector < int >visited (strs.size (), -1);
	vector < vector < string >> res;
	for (i = 0; i < strs.size (); i++)
	  {
		if (visited[i] == -1)
		  {
			vector < string > temp;
			temp.push_back (strs[i]);
			for (j = i + 1; j < strs.size (); j++)
			  {
				if (visited[j] == -1)
				  {
					int f = 0;
					for (int k = 0; k < 26; k++)
					  {
						if (freq[i][k] != freq[j][k])
						  {
							f = 1;
							break;
						  }
					  }
					if (f == 0)
					  {
						temp.push_back (strs[j]);
						visited[j] = 1;
					  }
				  }
			  }
			res.push_back (temp);
			visited[i] = 1;
		  }
	  }
	return res;
  }
};

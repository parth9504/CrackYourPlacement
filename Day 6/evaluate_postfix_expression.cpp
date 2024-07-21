class Solution
{
public:
  //Function to evaluate a postfix expression.
  int evaluatePostfix (string s)
  {
	int res = 0, i;
	  stack < int >st;
	for (i = 0; i < s.length (); i++)
	  {
		if (s[i] >= '0' && s[i] <= '9')
		  {
			st.push (s[i] - 48);
		  }
		else
		  {
			if (st.size () >= 2)
			  {
				int a = st.top ();
				st.pop ();
				int b = st.top ();
				st.pop ();
				if (s[i] == '+')
				  {
					st.push (a + b);
				  }
				else if (s[i] == '-')
				  {
					st.push (b - a);
				  }
				else if (s[i] == '*')
				  {
					st.push (b * a);
				  }
				else
				  {
					st.push (b / a);
				  }
			  }
		  }
	  }
	return st.top ();
  }
};

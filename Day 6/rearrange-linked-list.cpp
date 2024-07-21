class Solution
{
public:
  void rearrangeEvenOdd (Node * head)
  {
	//if <=2 nodes present
	if (head->next == NULL || head->next->next == NULL)
	  {
		return;
	  }
	vector < Node * >v;
	int i = 0;
	while (head != NULL)
	  {
		v.push_back (head);
		head = head->next;
	  }
	Node *prev = NULL;
	for (i = 0; i < v.size () - 2; i += 2)
	  {
		v[i]->next = v[i + 2];
		prev = v[i + 2];
	  }
	if (prev != NULL)
	  {
		prev->next = v[1];
	  }
	for (i = 1; i < v.size () - 2; i += 2)
	  {
		v[i]->next = v[i + 2];
	  }
	v[i]->next = NULL;
	head = v[0];
  }
};

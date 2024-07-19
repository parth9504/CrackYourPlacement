class Solution
{
public:
  //Function to sort a linked list of 0s, 1s and 2s.
  Node * segregate (Node * head)
  {
	int cz = 0, co = 0, ct = 0;
	Node *temp = head;
	while (temp != NULL)
	  {
		if (temp->data == 0)
		  {
			cz++;
		  }
		else if (temp->data == 1)
		  {
			co++;
		  }
		else
		  {
			ct++;
		  }
		temp = temp->next;
	  }

	temp = head;
	while (temp != NULL)
	  {
		if (cz > 0)
		  {
			temp->data = 0;
			cz--;
		  }
		else if (co > 0)
		  {
			temp->data = 1;
			co--;
		  }
		else
		  {
			temp->data = 2;
			ct--;
		  }
		temp = temp->next;
	  }

	return head;
  }
};

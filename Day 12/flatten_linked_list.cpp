#include<bits/stdc++.h>
Node* flattenLinkedList(Node* head)
{
	priority_queue<int>pq;
	int i;
	while(head!=NULL) {
		pq.push(head->data);
		//check if child pointer is not NULL
		if(head->child!=NULL) {
			Node *temp=head->child;
			while (temp != NULL) {
				pq.push(temp->data);
				temp = temp->child;
			}
		}
		head = head->next;
	}
	//cout<<pq.size();
	vector<Node*>v(pq.size());
	for (i = pq.size() - 1; i >= 0; i--) {
		v[i] = new Node(pq.top());
		pq.pop();
	}
	for (i = 0; i < v.size() - 1; i++) {
		v[i]->child = v[i + 1];
	}
	v[i]->child = NULL;
	return v[0];
}
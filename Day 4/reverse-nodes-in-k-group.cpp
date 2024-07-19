class Solution {
public:
    int length(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int i,j;
        int len = length(temp);
        if (k > len) {
            return head;
        }
        vector<ListNode*> v(k);
        ListNode *prev;
        ListNode* res;
        // the loop will run for a total of (len%k)-1 elements..
        // suppose len=5 and k=2, 5%2=1 means 1 element will not be a part of
        // any group..
        
        len = len - (len % k);
        temp = head;
        int count = 0,first = 0; // to keep track of elements put in the array(till k)
        for (int i = 0; i <len; i++) {
            //cout << count << " ";
            if (count < k) {
                //cout<<temp->val<<" ";
                v[count++] = temp;
                temp = temp->next;
            }
            //cout<<count<<" ";
            if (count == k) {
                if (first == 0) {
                    prev=v[0];  //previous node for 1st group
                    res = v[k - 1];
                    first++;
                }
                for (int j = k - 1; j > 0; j--) {
                    //cout<<v[j]->val<<" ";
                    v[j]->next = v[j - 1];
                }
                prev->next=v[k-1];
                prev=v[0];
                count = 0;
            }
        }
        if(temp==NULL){
            prev->next=NULL;}
        else{
            prev->next=temp;}
        return res;}};
       
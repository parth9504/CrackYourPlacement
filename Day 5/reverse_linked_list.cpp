class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;}
        vector<ListNode*>v;
        while(head!=NULL){
            v.push_back(head);
            head=head->next;}
        int i;
        for(i=v.size()-1;i>0;i--){
            v[i]->next=v[i-1];}
        v[i]->next=NULL;
        return v[v.size()-1];}};
      
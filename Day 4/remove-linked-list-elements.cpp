class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;}
        if(head->next==NULL){
            if(head->val==val){
                return NULL;}
            return head;}
        ListNode *temp=head;
        //if head has the same value as val
        if(temp->val==val){
            temp=temp->next;}

        while(temp!=NULL){
            if(temp->next!=NULL && temp->next->val==val){
                temp->next=temp->next->next;}
            else{
                temp=temp->next;}}
        
        while(head!=NULL && head->val==val){
            head=head->next;}
        return head;}};
    
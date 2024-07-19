class Solution {
public:
    int length(ListNode *head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;}
        return len;}
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //find length of the list.
        ListNode *temp=head;
        int len=length(temp);
        if(len==1 && n==1){
            return NULL;}
        //find the index of the node to delete from left side..
        len=len-n;
        if(len==0){
            head=head->next;
            return head;}
        temp=head;
        while(temp!=NULL){
            len--;
            if(len==0 && temp->next!=NULL){
                temp->next=temp->next->next;
                break;}
            else{
                temp=temp->next;}}
        return head;}};
          
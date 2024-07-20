class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        vector<ListNode*>arr1,arr2;
        int i,j;
        while(head1!=NULL){
            arr1.push_back(head1);
            head1=head1->next;}
        while(head2!=NULL){
            arr2.push_back(head2);
            head2=head2->next;}
     
        //iterate from behind till the nodes(address) is equal
        ListNode *prev=NULL;
        i=arr1.size()-1;
        j=arr2.size()-1;
        while(i>=0 && j>=0 && arr1[i]==arr2[j]){
            prev=arr1[i];
            i--;
            j--;
        }
        //if there was not intersection, i would remain the same
        return prev;}};
     
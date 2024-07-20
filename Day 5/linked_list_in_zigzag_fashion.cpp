class Solution {
  public:
    Node* zigZag(Node* head) {
       if(head==NULL || head->next==NULL){
           return head;}
        
        Node *temp=head;
        int flag=1; //when flag=1 the next node should be greater 
        while(temp->next!=NULL){
            if(flag==1){
                if(temp->data> temp->next->data){
                    swap(temp->data,temp->next->data);}}
            else{
                if(temp->data< temp->next->data){
                     swap(temp->data,temp->next->data);}}
            
            temp=temp->next;
            flag=!flag;}
    
        return head;}};
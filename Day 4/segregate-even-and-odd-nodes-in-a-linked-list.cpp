class Solution{
public:
    Node* divide(int N, Node *head){
        vector<Node*>v(N);
        int i=0;
        Node *temp=head;
        //store all the even numbers first..
        while(temp!=NULL){
            if(temp->data%2==0){
                v[i++]=temp;}
            temp=temp->next;}
        //store all the odd numbers first
        temp=head;
        while(temp!=NULL){
            if(temp->data%2==1){
                v[i++]=temp;}
            temp=temp->next;}
        
        //set the next for each node..
        for(i=0;i<N-1;i++){
            v[i]->next=v[i+1];}
        v[i]->next=NULL;
        return v[0];}};
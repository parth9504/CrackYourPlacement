class Solution
{
    public:
    Node *compute(Node *head)
    {
        vector<Node*>v;
        int i,j;
        while(head!=NULL){
            v.push_back(head);
            head=head->next;}
        vector<Node*>res;
        for(i=0;i<v.size();i++){
            int f=0;
            for(j=i+1;j<v.size();j++){
                if(v[j]->data> v[i]->data){
                    f=1;
                    break;}}
            if(f==0){
                res.push_back(v[i]);}}
        for(i=0;i<res.size()-1;i++){
            res[i]->next=res[i+1];}
        res[i]->next=NULL;
        return res[0];}};
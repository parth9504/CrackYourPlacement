class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;}
        vector<ListNode*>v;
        int i;
        for(i=0;i<lists.size();i++){
            while(lists[i]!=NULL){
                v.push_back(lists[i]);
                lists[i]=lists[i]->next;}}
        if(v.size()==0){
            return NULL;}
        sort(v.begin(),v.end(),[](auto a,auto b){
            return a->val<b->val;});
        for(i=0;i<v.size()-1;i++){
            v[i]->next=v[i+1];}
        v[i]->next=NULL;
        return v[0];}};
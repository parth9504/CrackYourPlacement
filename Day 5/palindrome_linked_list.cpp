class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return head;}
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;}
        int i,j;
        for(i=0,j=v.size()-1;i<v.size()/2;i++,j--){
            if(v[i]!=v[j]){
                return false;}}
        return true;}};
           
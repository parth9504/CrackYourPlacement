/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return head;}
        
        vector<ListNode*>v;
        ListNode *temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                v.push_back(temp);}
            temp=temp->next;}
        temp=head;
        while(temp!=NULL){
            if(temp->val>=x){
                v.push_back(temp);}
            temp=temp->next;}
        
        int i;
        for(i=0;i<v.size()-1;i++){
            v[i]->next=v[i+1];}
        v[i]->next=NULL;
        return v[0];}};
    
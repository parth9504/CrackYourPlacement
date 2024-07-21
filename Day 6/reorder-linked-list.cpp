class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next==NULL || head->next->next==NULL){
            return;}
        vector<ListNode*> v;
        while (head != NULL) {
            v.push_back(head);
            head = head->next;
        }
        int i, j;
        ListNode* prev = NULL;
        for (i = 0, j = v.size() - 1; i < v.size() / 2; i++, j--) {
            if (prev != NULL) {
                prev->next = v[i];
            }
            v[i]->next = v[j];
            prev = v[j];
        }
        if(v.size()%2==1){
            prev->next=v[i];
            prev=prev->next;}
        prev->next = NULL;
        head = v[0];
    }
};
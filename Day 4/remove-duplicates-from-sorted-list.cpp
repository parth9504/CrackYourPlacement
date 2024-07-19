class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* itr = head;
        while (itr != NULL) {
            if (itr->next != NULL && itr->val == itr->next->val) {
                itr->next = itr->next->next;
            } else {
                itr = itr->next;
            }
        }
        return head;
    }
};

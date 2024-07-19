class Solution {
public:
    int length(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int len = length(temp), i = 0;
        while (i++ < len/2) {
            head = head->next;
        }
        return head;
    }
};

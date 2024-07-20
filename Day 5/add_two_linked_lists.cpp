class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        vector<ListNode*> res;
        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1 != NULL && l2 != NULL) {
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1 != NULL) {
                sum = l1->val;
                l1 = l1->next;
            } else {
                sum = l2->val;
                l2 = l2->next;
            }

            sum += carry;
            if (carry == 1) {
                carry = 0;
            }
            res.push_back(new ListNode(sum % 10));
            if (sum > 9) {
                carry = 1;
            }
        }

        if (carry == 1) {
            res.push_back(new ListNode(1));
        }
        int i;
        for (i = 0; i < res.size() - 1; i++) {
            res[i]->next = res[i + 1];
        }
        res[i]->next = NULL;

        return res[0];
    }
};

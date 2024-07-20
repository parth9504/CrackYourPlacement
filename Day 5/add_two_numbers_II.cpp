class Solution {
public:
    ListNode* reverse(ListNode* temp) {
        vector<ListNode*> rev;
        int i;
        while (temp != NULL) {
            rev.push_back(temp);
            temp = temp->next;
        }
        for (i = rev.size() - 1; i > 0; i--) {
            rev[i]->next = rev[i - 1];
        }
        rev[i]->next = NULL;
        return rev[rev.size() - 1];
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse the lists
        int i;
        ListNode* temp = l1;
        l1 = reverse(temp);
        temp = l2;
        l2 = reverse(temp);

        vector<ListNode*> res;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum;
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
            carry = 0;
            res.push_back(new ListNode(sum % 10));
            if (sum > 9) {
                carry = 1;
            }
        }
        if (carry == 1) {
            res.push_back(new ListNode(1));
        }
        for (i = res.size() - 1; i > 0; i--) {
            res[i]->next = res[i - 1];
        }
        res[i]->next = NULL;

        return res[res.size() - 1];
    }
};

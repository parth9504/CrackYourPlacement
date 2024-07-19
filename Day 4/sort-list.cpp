class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        vector<ListNode*> v;
        while (head != NULL) {
            v.push_back(head);
            head = head->next;
        }
        sort(v.begin(), v.end(),
             [](auto a, auto b) { return a->val < b->val; });
        int i;
        for (i = 0; i < v.size() - 1; i++) {
            v[i]->next = v[i + 1];
        }
        v[i]->next = NULL;

        return v[0];
    }
};

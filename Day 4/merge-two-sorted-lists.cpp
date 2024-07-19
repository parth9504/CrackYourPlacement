class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // IF BOTH EMPTY
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        // IF EITHER OF THEM EMPTY
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        vector<ListNode*> v;
        while (list1 != NULL) {
            v.push_back(list1);
            list1 = list1->next;
        }

        while (list2 != NULL) {
            v.push_back(list2);
            list2 = list2->next;
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
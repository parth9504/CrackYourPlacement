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
    ListNode* deleteDuplicates(ListNode* head) {
        map < int, int > mp;
        while (head != NULL) {
            mp[head->val]++;
            head = head->next;
        }
        ListNode* res = NULL;
        ListNode* p = NULL;
        for (auto it : mp) {
            if (it.second == 1) {
                ListNode* temp = new ListNode(it.first);
                if (res == NULL) {
                    res = temp;
                } else {
                    p->next = temp;
                }
                p = temp;
            }
        }
        return res;
    }
};

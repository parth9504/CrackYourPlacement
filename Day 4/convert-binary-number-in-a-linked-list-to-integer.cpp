class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s = "";
        while (head != NULL) {
            s += to_string(head->val);
            head = head->next;
        }
        int num=0, k = 0, i;
        for (i = s.length() - 1; i >= 0; i--, k++) {
            if (s[i] == '1') {
                num += (int)pow(2, k);
            }
        }
        return num;
    }
};

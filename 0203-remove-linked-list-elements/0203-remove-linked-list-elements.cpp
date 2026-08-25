class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }

        head->next = removeElements(head->next, val);

        if (head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        return head;
    }
};
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
    ListNode* solve(ListNode* l1, ListNode* l2, int carry) {
        
        
        if (l1 == NULL && l2 == NULL && carry == 0) {
            return NULL;
        }

        int sum = carry;

        if (l1 != NULL)
            sum += l1->val;

        if (l2 != NULL)
            sum += l2->val;

        
        ListNode* newNode = new ListNode(sum % 10);

        
        ListNode* next1 = (l1 != NULL) ? l1->next : NULL;
        ListNode* next2 = (l2 != NULL) ? l2->next : NULL;

        newNode->next = solve(next1, next2, sum / 10);

        return newNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
};
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
    int getDecimalValue(ListNode* head) {
        vector<int> bits;

        while (head != NULL) {
            bits.push_back(head->val);
            head = head->next;
        }

        int ans = 0;
        int power = 1;  

        for (int i = bits.size() - 1; i >= 0; i--) {
            ans += bits[i] * power;
            power *= 2;
        }

        return ans;
    }
};
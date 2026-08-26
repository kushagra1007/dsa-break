/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr = headA;
        unordered_set<ListNode*> st;
        while(curr != NULL){
            st.insert(curr);
            curr = curr->next;
        }
        curr = headB;
        while(curr != NULL){
            if(st.find(curr) != st.end()){
                return curr;

            }
            curr = curr->next;
        }
        return NULL;
    }
};
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
        ListNode *ta = headA;
        ListNode *tb = headB;

        if(!ta || !tb) return NULL;

        while(ta!=tb){
            ta = ta->next;
            tb = tb->next;

            if(ta == tb) return ta;
            if(!ta) ta = headB;
            if(!tb) tb = headA;
        }

        return ta;
    }
};
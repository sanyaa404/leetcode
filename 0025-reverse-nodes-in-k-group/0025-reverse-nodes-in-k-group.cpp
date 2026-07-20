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
private:
    ListNode* reverseLL(ListNode* head, ListNode* end){
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != end){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* end = head;
        for(int i=0; i<k; i++){
            if (!end) return head;
            end = end->next;
        }
        
        ListNode* newhead = reverseLL(head, end);
        ListNode* khead = reverseKGroup(end, k);
        head->next = khead;
        return newhead;
    }
};
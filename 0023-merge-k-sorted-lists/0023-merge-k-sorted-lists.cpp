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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(true){
            int idx = -1;
            int mini = INT_MAX;
            for(int i=0; i<k; i++){
                if(lists[i]&& lists[i]->val < mini){
                    mini = lists[i]->val;
                    idx = i;
                }
            }
            if(idx == -1) break;
            curr->next = new ListNode(lists[idx]->val);
            lists[idx] = lists[idx]->next; curr = curr->next;
        }

        return dummy->next;
    }
};
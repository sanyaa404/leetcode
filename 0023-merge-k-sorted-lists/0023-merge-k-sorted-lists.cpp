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
        using pl = pair<int, ListNode*>;
        priority_queue<pl, vector<pl>, greater<pl> > minh;
        for(auto list : lists){
            if(list) minh.push({list->val, list});
        }
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(!minh.empty()){
            ListNode* node = minh.top().second; minh.pop();
            temp->next = node;
            temp = temp->next;
            if(node->next) minh.push({node->next->val, node->next});
        }
        head = head->next;
        return head;
    }
};
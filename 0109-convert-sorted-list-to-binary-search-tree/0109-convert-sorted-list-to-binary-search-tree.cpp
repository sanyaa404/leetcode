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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        if(!head) return 0;
        ListNode* temp = head;
        int cnt = 0;

        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        int n = length(head);

        ListNode* temp = head;
        int mid = n / 2;
        for(int i=1; i<mid; i++){
            temp = temp->next;
        }
        //temp is now tail of left sublist
        ListNode* rootNode = temp->next;
        temp->next = NULL;
        TreeNode* root = new TreeNode(rootNode->val);
        ListNode* left = head;
        ListNode* right = rootNode->next;
        // rootNode->next = NULL;
        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right);

        return root;
    }
};
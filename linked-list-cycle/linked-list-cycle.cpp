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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> umap;
        while(true){
            if(head==NULL){
                return false;
            }
            if(umap[head]){
                return true;
            }
            umap[head]=true;
            head=head->next;
        }
        return false;
    }
};
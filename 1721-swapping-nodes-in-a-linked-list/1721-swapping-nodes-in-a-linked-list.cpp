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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1;
        ListNode* n2;
        ListNode* temp=head;
        while(k>0){
            k--;
            n1=head;
            head=head->next;
        }
        n2=temp;
        while(head!=NULL){
            n2=n2->next;
            head=head->next;
        }
        swap(n1->val, n2->val);
        return temp;
    }
};
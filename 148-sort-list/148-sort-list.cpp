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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        vector<int> nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head=head->next;
        }
        sort(nums.begin(), nums.end());
        ListNode* node=new ListNode(nums[0]);
        ListNode* prev=node;
        for(int i=1; i<nums.size(); i++){
            ListNode* temp = new ListNode(nums[i]);
            prev->next=temp;
            prev=temp;
        }
        return node;
    }
};
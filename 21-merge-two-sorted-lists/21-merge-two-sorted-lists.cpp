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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* ans=NULL;
        ListNode* prev=NULL;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                if(ans==NULL){
                    ans=new ListNode(temp1->val);
                    prev=ans;
                    temp1=temp1->next;
                }
                else{
                    prev->next=new ListNode(temp1->val);
                    prev=prev->next;
                    temp1=temp1->next;
                }
            }
            else{
                if(ans==NULL){
                    ans=new ListNode(temp2->val);
                    prev=ans;
                    temp2=temp2->next;
                    continue;
                }
                else{
                    prev->next=new ListNode(temp2->val);
                    prev=prev->next;
                    temp2=temp2->next;
                }
            }
        }
        while(temp1!=NULL){
            if(ans==NULL){
                ans=new ListNode(temp1->val);
                prev=ans;
                temp1=temp1->next;
                continue;
            }
            prev->next=new ListNode(temp1->val);
            prev=prev->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            if(ans==NULL){
                ans=new ListNode(temp2->val);
                prev=ans;
                temp2=temp2->next;
                continue;
            }
            prev->next=new ListNode(temp2->val);
            prev=prev->next;
            temp2=temp2->next;
        }
        return ans;
    }
};
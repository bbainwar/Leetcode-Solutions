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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        unordered_map<int, int> count;
        while(head!=NULL){
            s.insert(head->val);
            count[head->val]++;
            head=head->next;
        }
        bool flag=false;
        ListNode* node;
        ListNode* prev;
        for(auto itr=s.begin(); itr!=s.end(); itr++){
            if(count[*itr]>1) continue;
            if(flag==false){
                flag=true;
                node = new ListNode(*itr);
                prev=node;
                continue;
            }
            prev->next=new ListNode(*itr);
            prev=prev->next;
        }
        return node;
    }
};
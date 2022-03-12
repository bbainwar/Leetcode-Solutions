/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        
        unordered_map<Node*, Node*> ran;
        unordered_map<Node*, Node*> oldNew;
        unordered_map<Node*, Node*> newOld;
       
        Node* node=head;
        head=new Node(node->val);
        oldNew[node]=head;
        newOld[head]=node;
        ran[node]=node->random;
        Node* prev=head;
        node=node->next;
        
        while(node!=NULL){
            prev->next=new Node(node->val);
            oldNew[node]=prev->next;
            newOld[prev->next]=node;
            ran[node]=node->random;
            node=node->next;
            prev=prev->next;
        }
        node=head;
        while(head!=NULL){
            head->random=oldNew[ran[newOld[head]]];
            head=head->next;
        }
        return node;
    }
};
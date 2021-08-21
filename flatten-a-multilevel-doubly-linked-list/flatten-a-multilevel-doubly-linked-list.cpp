/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solution(Node* head){
        if(head->next==NULL && head->child==NULL){
            return head;
        }
        if(head->child!=NULL){
            Node* nextNode;
            nextNode=head->next;
            head->child->prev=head;
            head->next=head->child;
            head->child=NULL;
            Node* finalNode=solution(head->next);
            finalNode->next=nextNode;
            if(nextNode!=NULL)
            nextNode->prev=finalNode;
            return solution(head->next);
        }
        return solution(head->next);
        
    }
    Node* flatten(Node* head) {
        if(head==NULL){return head;}
        Node* temp = solution(head);
        return head;
    }
};
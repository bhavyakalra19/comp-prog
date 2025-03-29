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
    Node* flatten(Node* head) {
        Node *p = head;
        while(p){
            if(p->child){
                Node *childList = flatten(p->child);
                Node *lastNode = childList;
                while(lastNode->next){
                    lastNode = lastNode->next;
                }
                lastNode->next = p->next;
                if(lastNode->next) lastNode->next->prev = lastNode;
                p->child = NULL;
                p->next = childList;
                childList->prev = p;
            }
            p = p->next;
        }
        return head;
    }
};
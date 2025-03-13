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
        if(!head) return head;
        unordered_map<int, Node*> mp;
        unordered_map<Node*,int> main;
        Node *newHead = new Node(head->val);
        Node *q = newHead;
        mp[0] = newHead;
        main[head] = 0;
        Node *p = head->next;
        int idx = 1;
        while(p){
            main[p] = idx;
            Node *temp = new Node(p->val);
            q->next = temp;
            q = temp;
            mp[idx++] = q;
            p = p->next;
        }
        p = head;
        q = newHead;
        while(p){
            if(p->random){
                q->random = mp[main[p->random]];
            }
            p = p->next;
            q = q->next;
        }
        return newHead;
    }
};
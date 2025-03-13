class Node{
public:
    int val;
    int data;
    Node *next;
    Node *prev;

    Node(int a, int b){
        val = a;
        data = b;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    Node *head;
    Node *tail;
    int cap;
    int curr;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
        curr = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end() || mp[key] == NULL) return -1;
        Node *temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
        return temp->data;
    }
    
    void put(int key, int value) {
        Node *temp;
        if(mp.find(key) == mp.end() || mp[key] == NULL){
            if(curr == cap){
                Node *t = tail->prev;
                t->prev->next = t->next;
                t->next->prev = t->prev;
                mp[t->val] = NULL;
            }else{
                curr++;
            }
            temp = new Node(key, value);
            mp[key] = temp;
        }else{
            temp = mp[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->data = value;
        }
        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
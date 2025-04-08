class Node{
    public:
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int k, int v){
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
};

class LRUCache {
public:
    Node *head;
    Node *tail;
    unordered_map<int, Node*> mp;
    int cap;
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end() || mp[key] == NULL) return -1;
        Node *temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head->next;
        temp->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != NULL && mp[key] != NULL){
            Node *temp = mp[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = head->next;
            temp->next->prev = temp;
            head->next = temp;
            temp->prev = head;
            temp->val = value;
        }else{
            Node *temp = new Node(key, value);
            mp[key] = temp;
            temp->next = head->next;
            temp->next->prev = temp;
            head->next = temp;
            temp->prev = head;
            if(cap != 0){
                cap--;
            }else{
                temp = tail->prev;
                tail->prev = temp->prev;
                temp->prev->next = tail;
                mp[temp->key] = NULL;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class Node{
    public:
        int key;
        int data;
        Node *prev;
        Node *next;

        Node(int key, int data){
            this->data = data;
            this->key = key;
        }
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int cap;
    int curr;
    Node *head;
    Node *tail;
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
        curr = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end() || mp[key] == NULL){
            return -1;
        }
        Node *last = mp[key];
        last->prev->next = last->next;
        last->next->prev = last->prev;
        last->next = head->next;
        head->next->prev = last;
        head->next = last;
        last->prev = head;
        return last->data;
    }
    
    void put(int key, int value) {
        Node *last;
        if(mp.find(key) != mp.end() && mp[key] != NULL){
            last = mp[key];
            last->prev->next = last->next;
            last->next->prev = last->prev;
            last->data = value;
        }else{
            if(cap == curr){
                Node *nw = tail->prev;
                nw->prev->next = nw->next;
                nw->next->prev = nw->prev;
                mp[nw->key] = NULL;
            }else{
                curr++;
            }
            last = new Node(key, value);
        }
        mp[key] = last;
        last->next = head->next;
        head->next->prev = last;
        head->next = last;
        last->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class Node{
    public:
        int key;
        int data;
        Node *prev;
        Node *next;

        Node(int k, int d){
            key = k;
            data = d;
            next = NULL;
            prev = NULL;
        }
};

class LRUCache {
public:
    int cap;
    int curr;
    Node *head;
    Node *tail;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        curr = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end() || mp[key] == NULL){
            return -1;
        }
        Node *temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        return temp->data;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end() && mp[key] != NULL){
            Node *temp = mp[key];
            temp->data = value;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
        }else{
            if(curr == cap){
                Node *last = tail->prev;
                mp[last->key] = NULL;
                last->prev->next = tail;
                tail->prev = last->prev;

            }else{
                curr++;
            }
            Node *temp = new Node(key, value);
            mp[key] = temp;
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            temp->prev = head;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
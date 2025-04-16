class Node{
    public:
        int data;
        int key;
        int cnt;
        Node *next;
        Node *prev;

        Node(int k, int d){
            key = k;
            data = d;
            cnt = 1;
            next = NULL;
            prev = NULL;
        }
};

class LFUCache {
public:
    int curr;
    int cap;
    int freq;
    unordered_map<int,Node*> key_map;
    unordered_map<int,pair<Node*,Node*>> freq_map;
    LFUCache(int capacity) {
        freq = 1;
        curr = 0;
        cap = capacity;
    }

    void addToFreq(int freq, Node *temp){
        Node *head;
        Node *tail;
        if(freq_map.find(freq) == freq_map.end()){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            freq_map[freq] = {head,tail};
        }else{
            auto it = freq_map[freq];
            head = it.first;
            tail = it.second;
        }
        head->next->prev = temp;
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
    }
    
    void updateFreq(Node *last){
        last->prev->next = last->next;
        last->next->prev = last->prev;
        int old_freq = last->cnt;
        last->cnt += 1;
        if(freq == old_freq && freq_map[freq].first->next == freq_map[freq].second){
            freq++;
        }
        addToFreq(last->cnt, last);
    }

    int get(int key) {
        if(key_map.find(key) == key_map.end() || key_map[key] == NULL) return -1;
        Node *last = key_map[key];
        updateFreq(last);
        return last->data;
    }
    
    void put(int key, int value) {
        if(key_map.find(key) == key_map.end() || key_map[key] == NULL){
            if(curr < cap){
                curr++;
            }else{
                auto it = freq_map[freq];
                Node *tail = it.second;
                Node *last = tail->prev;
                last->prev->next = tail;
                tail->prev = last->prev;
                key_map[last->key] = NULL;
            }
            Node *temp = new Node(key, value);
            key_map[key] = temp;
            freq = 1;
            addToFreq(1, temp);
        }else{
            Node *last = key_map[key];
            last->data = value;
            updateFreq(last);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
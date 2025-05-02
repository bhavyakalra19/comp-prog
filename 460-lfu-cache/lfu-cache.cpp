class Node{
    public:
        int key;
        int data;
        int cnt;
        Node *prev;
        Node *next;

        Node(int k, int d){
            prev = NULL;
            next = NULL;
            cnt = 1;
            key = k;
            data = d;
        }
};

class LFUCache {
public:
    int freq;
    int curr_cap;
    int cap;
    unordered_map<int,Node*> key_map;
    unordered_map<int,pair<Node*,Node*>> freq_map;
    LFUCache(int capacity) {
        freq = 1;
        curr_cap = 0;
        cap = capacity;
    }
    void addFreq(Node *temp){
        int curr_freq = temp->cnt;
        // temp->prev->next = temp->next;
        // temp->next->prev = temp->prev;

        // if(freq_map[curr_freq].first->next == freq_map[curr_freq].second){
        //     freq = curr_freq+1;
        // }
        // curr_freq++;
        Node *head;
        Node *tail;
        if(freq_map.find(curr_freq) == freq_map.end()){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            freq_map[curr_freq] = make_pair(head, tail);
        }else{
            head = freq_map[curr_freq].first;
        }
        head->next->prev = temp;
        temp->next = head->next;
        head->next = temp;
        temp->prev = head;
    }
    
    void updateFreq(Node *temp){
        int curr_freq = temp->cnt;
        if(freq == curr_freq && freq_map[curr_freq].first->next == freq_map[curr_freq].second){
            freq = curr_freq+1;
        }
        temp->cnt += 1;
    }
    
    int get(int key) {
        //if key doesnt exists
        if(key_map.find(key) == key_map.end() || key_map[key] == NULL){
            return -1;
        }
         //if key exists
        Node *last = key_map[key];
        last->prev->next = last->next;
        last->next->prev = last->prev;
        updateFreq(last);
        addFreq(key_map[key]);  
        return last->data;
    }
    
    void put(int key, int value) {
        //if key exists
        if(key_map.find(key) != key_map.end() && key_map[key] != NULL){
            Node *last = key_map[key];
            last->prev->next = last->next;
            last->next->prev = last->prev;
            updateFreq(last);
            addFreq(key_map[key]);
            last->data = value;
        }else{
            //if key doesn't exist
            //if capacity is full
            Node *last;
            if(curr_cap == cap){
                last = freq_map[freq].second->prev;
                last->next->prev = last->prev;
                last->prev->next = last->next;
                updateFreq(last);
                key_map[last->key] = NULL;
            }else{
            //if capacity not full
                curr_cap += 1;
            }
            freq = 1;
            last = new Node(key, value);
            addFreq(last);
            key_map[key] = last;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
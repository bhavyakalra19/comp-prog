class Node{
    public:
        int data;
        int key;
        int cnt;
        Node *next;
        Node *prev;
        Node(int k, int d){
            //freq 1 for new one
            cnt = 1;
            next = NULL;
            prev = NULL;
            key = k;
            data = d;
        }
};

class LFUCache {
public:
    int curr;
    int cap;
    int freq;
    unordered_map<int,Node*> key_map;
    unordered_map<int, pair<Node*, Node*>> freq_map;
    LFUCache(int capacity) {
        cap = capacity;
        curr = 0;
        freq = 1;
    }
    
    int get(int key) {
        if(key_map.find(key) == key_map.end() || key_map[key] == NULL){
            return -1;
        }
        Node *last = key_map[key];
        last->prev->next = last->next;
        last->next->prev = last->prev;
        int old_freq = last->cnt;
        if(freq == old_freq){
            if(freq_map[old_freq].first->next == freq_map[old_freq].second){
                freq++;
            }
        }
        last->cnt += 1;
        addFreq(last->cnt, last);
        return last->data;
    }

    void addFreq(int freq, Node *temp){
        Node *head;
        Node *tail;
        if(freq_map.find(freq) == freq_map.end()){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            freq_map[freq] = {head, tail};
        }else{
            auto it = freq_map[freq];
            head = it.first;
            tail = it.second;
        }
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }
    
    void put(int key, int value) {
        //if key doesn't exist
        if(key_map.find(key) == key_map.end() || key_map[key] == NULL){
            //curr < cap
            if(curr < cap){
                curr++;
            }else{
                //curr == cap
                auto it = freq_map[freq];
                Node *last = it.second->prev;
                Node *tail = it.second;
                last->prev->next = tail;
                tail->prev = last->prev;
                key_map[last->key] = NULL;
            }
            freq = 1;
            Node *temp = new Node(key, value);
            key_map[key] = temp;
            addFreq(freq, temp);
        }else{
            //if key exist
            Node *last = key_map[key];
            last->data = value;
            last->prev->next = last->next;
            last->next->prev = last->prev;
            int old_freq = last->cnt;
            if(freq == old_freq){
                if(freq_map[old_freq].first->next == freq_map[old_freq].second){
                    freq++;
                }
            }
            last->cnt += 1;
            addFreq(last->cnt, last);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
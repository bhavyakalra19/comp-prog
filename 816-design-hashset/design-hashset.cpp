class Node{
    public:
        int val;
        Node *next;
        
        Node(int data){
            val = data;
            next = NULL;
        }
};

class MyHashSet {
public:
    int n;
    vector<Node*> check;
    MyHashSet() {
        n = 100;
        for(int i = 0; i <= n; i++){
            Node *temp = new Node(-1);
            check.push_back(temp);
        }
    }
    
    void add(int key) {
        int newKey = (key % n);
        cout << newKey << endl;
        Node *temp = check[newKey]; 
        while(temp->next){
            temp = temp->next;
            if(temp->val == key) return;
        }
        Node *newNode = new Node(key);
        temp->next = newNode;
    }
    
    void remove(int key) {
        int newKey = key % n;
        Node *temp = check[newKey];
        while(temp->next && temp->next->val != key){
            temp = temp->next;
        }
        if(!temp->next) return;
        temp->next = temp->next->next;
    }
    
    bool contains(int key) {
        int newKey = key % n;
        Node *temp = check[newKey];
        while(temp){
            if(temp->val == key) return true;
            temp = temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
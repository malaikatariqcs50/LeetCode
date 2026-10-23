//Last Solved on: 23 OCT, 2026, Friday
//Last Solved in: 1 hour

class LRUCache {
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int c;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

public:
    LRUCache(int capacity) {
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode){
        Node* firstNode = head->next;
        newNode->next = firstNode; 
        newNode->prev = head;
        head->next = newNode;
        firstNode->prev = newNode;
    }

    void deleteNode(Node* delNode){ 
        Node* prev = delNode->prev;
        prev->next = delNode->next; 
        delNode->next->prev = prev;
    }
    
    int get(int key) { 
        if(mp.count(key)){
            Node* node = mp[key];
            int value = node->value; 
            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key] = head->next;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){ 
            Node* node = mp[key]; 
            mp.erase(key);
            deleteNode(node);
            delete node;
        }
        if(mp.size() == c){ 
            Node* node = tail->prev;
            mp.erase(node->key);
            deleteNode(node);
            delete node;
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

//Pattern: Doubly linked list + hashmap
//For O(1) look up, use hashmap
//Use doubly linked list for nodes with key and value
//Whenever a node is changed/added/called, put it at the start
//If the capacity is full, remove the last node
//Last Solved on: 21 Oct, 2026, Wednesday
//Last Solved in: 1 hour

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node* current = head;
        unordered_map<Node*, Node*> mp;
        while(current != nullptr){
            mp[current] = new Node(current->val);
            current = current->next;
        }

        current = head;
        while(current != nullptr){
            mp[current]->next = mp[current->next];
            mp[current]->random = mp[current->random];
            current = current->next;
        }
        return mp[head];
    }
};

//Pattern: Create a copy of every node against the original node in the map
//Then using the original nodes, find the copied nodes values stored in map and assign them
//Return using head of the original (to find the value of copied)
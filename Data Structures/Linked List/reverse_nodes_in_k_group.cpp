//Last Solved on: 23 Oct, 2026, Friday
//Last Solved in: 45 mins

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* first = head; 
        ListNode* saved = nullptr;
        ListNode* list = head;

        int iteration = 1;

        while (current != nullptr) {
            int count = 1;
            while (current != nullptr && count < k) { 
                count++;                              
                current = current->next;
            }
            if (current == nullptr) {
                break;
            }
            int i = 0;
            prev = current->next;                 
            current = first;                      
            while (current != nullptr && i < k) { 
                ListNode* next = current->next;   
                current->next = prev;             
                prev = current;                   
                current = next;                   
                i++;
                if (i >= k) {
                    if (saved != nullptr) {
                        saved->next = prev;
                    }
                    saved = first; 
                    first = next; 
                }
            }
            if(iteration == 1){
                list = prev;
                iteration++;
            }
        }
        return list;
    }
};

//Pattern: Save the first node; Reverse each node in a loop that runs k times;
//FirstNode->next = nextGroup
//In the first oteration, after reversing, save the first node and return at the end
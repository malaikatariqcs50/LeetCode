//Last Solved on: 19 Oct, 2026, Monday
//Last Solved in: 10 minutes
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

//Pattern: Make a slow and fast pointer, if they ever meet, that means there is a cycle
//If they reach null, that means there is no cycle
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow=slow->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        
        ListNode* prev = nullptr;
        while(second){
            ListNode* next = second->next;
            second->next = prev;
            prev = second; 
            second = next; 
        }
        
        ListNode* current = head;
        while(prev){ 
            ListNode* temp = current->next;
            current->next=prev;
            prev=prev->next; 
            current = current->next;
            current->next=temp;
            current=current->next;
        }
        
    }
};
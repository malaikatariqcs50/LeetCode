//Last Solved on: 26 Oct, 2026, Monday
//Last Solved in: 10 minutes

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        if(fast == nullptr){
            ListNode* next = head->next;
            delete head;
            return next;
        }

        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};

//Pattern: Keep the gap between slow and fast pointers
//When fast reaces the end, remove the next node after slow
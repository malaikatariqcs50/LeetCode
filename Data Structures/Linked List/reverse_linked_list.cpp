//Last Solved on: 19 Oct, 2026
//Last Solved in: 10 mins

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

//Reversing: next becomes prev, prev becomes current, current becomes next;
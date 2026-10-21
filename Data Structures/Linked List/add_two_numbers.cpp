//Last Solved in: 30 mins
//Last Solved on: 21 Oct, 2026, Wednesday

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy;
        ListNode* current = &dummy;
        
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int val1 = 0;
            int val2 = 0;

            if(l1 != nullptr){
                val1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                val2 = l2->val;
                l2 = l2->next;
            }

            int sum = val1 + val2 + carry;
            current->next = new ListNode(sum % 10);
            carry = sum / 10;

            current = current->next;
        }
        return dummy.next;
    }
};

//Pattern: Add the two numbers and carry, save their sum % 10. Carry = sum / 10;
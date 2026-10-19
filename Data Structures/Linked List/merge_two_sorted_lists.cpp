//Last Solved on: 19 Oct, 2026, Monday
//Last Solved in: 15 mins
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* current = &dummy;
        
        while(l1 != nullptr && l2 != nullptr){
            int val1 = l1->val;
            int val2 = l2->val;
            
            if(val1 > val2){
                current->next = l2;
                l2=l2->next;
            }
            else{
                current->next = l1;
                l1=l1->next;
            }
            current = current->next;
        }
        if(l1 != nullptr){
            current->next = l1;
        }
        if(l2 != nullptr){
            current->next = l2;
        }
        return dummy.next;
    }
};

//Pattern: Attach the list whose current value is smaller
//Make an empty ListNode first and another which points to the empty one and apply the operations on it.
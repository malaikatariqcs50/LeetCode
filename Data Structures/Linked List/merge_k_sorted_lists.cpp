//Last Solved on: 23 Oct, 2026, Friday
//Last Solved in: 45 mins

class Solution {
private:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* current = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val >= l2->val) {
                current->next = l2;
                l2 = l2->next;
            } else {
                current->next = l1;
                l1 = l1->next;
            }
            current = current->next;
        }
        if (l1 != nullptr) {
            current->next = l1;
        }
        if (l2 != nullptr) {
            current->next = l2;
        }
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        vector<ListNode*> mergedLists;
        while (lists.size() > 1) {
            mergedLists.clear();
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeLists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};

//Pattern: Merge Two Lists at a time
//Make the resulting reduced lists -> actual lists
//In the reduced lists, merge two at a time again and keep dgoing until one sorted list is left
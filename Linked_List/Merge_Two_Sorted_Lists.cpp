/*
LeetCode 21 - Merge Two Sorted Lists

Approach:
- Create a dummy node to simplify handling of the merged list.
- Maintain a tail pointer representing the last node of the merged list.
- Compare the current nodes of both lists:
    - Attach the smaller node to tail.
    - Move the corresponding list pointer forward.
- Advance tail after each insertion.
- After one list is exhausted, attach the remaining nodes
  of the other list directly.
- Return dummyNode->next as the head of the merged list.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;

        while(list1 && list2) {

            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Attach the remaining list
        tail->next = list1 ? list1 : list2;

        return dummyNode->next;
    }
};

/*
LeetCode 2 - Add Two Numbers

Approach:
- Use a Dummy Node and Tail Pointer to build the result list.
- Traverse both linked lists simultaneously.
- At each step:
    - Add the current digits from both lists and the carry.
    - Create a new node with (sum % 10).
    - Update carry as (sum / 10).
- Continue until:
    - Both lists are exhausted, and
    - No carry remains.
- Return dummy->next as the head of the resulting list.

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))
(Result linked list excluding input lists)
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        int carry = 0;

        while(l1 || l2 || carry) {

            int sum = carry;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            int element = sum % 10;

            tail->next = new ListNode(element);
            tail = tail->next;
        }

        return dummy->next;
    }
};

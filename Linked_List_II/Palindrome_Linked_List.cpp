/*
LeetCode 234 - Palindrome Linked List

Approach:
- Use Fast & Slow pointers to find the middle of the linked list.
- Reverse the second half of the list.
- Compare nodes from the first half and reversed second half.
- If any pair of nodes differs, the list is not a palindrome.
- If all corresponding nodes match, the list is a palindrome.

Time Complexity:
- O(n/2) : Find the middle node
- O(n/2) : Reverse the second half
- O(n/2) : Compare both halves
- Overall: O(n)

Space Complexity:
- O(1) : In-place reversal of the second half
- Overall: O(1)

Revision Keywords:
- Fast & Slow Pointer
- Middle Node
- Reverse Second Half
- Two Half Comparison
- In-Place Check
- Palindrome Linked List
*/

class Solution {
public:

    ListNode* reverseLL(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fut;

        while(curr) {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(!head->next)
            return true;

        // Find middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while((fast && fast->next) && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* temp1 = reverseLL(slow->next);

        // Compare both halves
        ListNode* temp = head;

        while(temp1 != NULL) {

            if(temp1->val != temp->val)
                return false;

            temp1 = temp1->next;
            temp = temp->next;
        }

        return true;
    }
};

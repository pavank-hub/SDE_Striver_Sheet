/*
LeetCode 25 - Reverse Nodes in k-Group

Approach:
- Process the linked list in groups of size k.
- Find the kth node from the current starting node.
- If fewer than k nodes remain, attach the remaining list as is.
- Detach the current group and reverse it using standard linked list reversal.
- Connect the reversed group to the previously processed part.
- Repeat until all possible groups are processed.

Time Complexity:
- O(n/k) : Number of groups processed
- O(k)   : Finding kth node for each group
- O(k)   : Reversing each group
- Overall: O(n)

Space Complexity:
- O(1) : Only pointer manipulation is used
- Overall: O(1)

Revision Keywords:
- Reverse Linked List
- Kth Node
- Group Reversal
- Detach & Reconnect
- Dummy Node
- Linked List Hard
*/

class Solution {
public:

    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL, *curr = head, *fut;

        while(curr) {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k) {
        ListNode* curr = temp;

        while(curr && k--)
            curr = curr->next;

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head->next || k == 1)
            return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* temp = head;

        while(temp) {

            ListNode* kthNode = findKthNode(temp, k - 1);

            if(kthNode == NULL) {
                tail->next = temp;
                break;
            }

            ListNode* futNode = kthNode->next;
            kthNode->next = NULL;

            tail->next = reverseLL(temp);

            tail = temp;
            temp = futNode;
        }

        return dummy->next;
    }
};

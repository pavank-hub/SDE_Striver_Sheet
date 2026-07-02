/*
LeetCode 237 - Delete Node in a Linked List

Approach:
- The given node is guaranteed not to be the tail node.
- Copy the value of the next node into the current node.
- Update the current node's next pointer to skip the next node.
- Delete the original next node.
- This effectively removes the given node without needing access
  to the head of the linked list.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* temp = node->next;

        node->val = temp->val;
        node->next = temp->next;

        delete temp;
    }
};

/*
LeetCode 138 - Copy List with Random Pointer

Approach:
- Use the Interweaving Linked List technique.
- Step 1:
    - Create a copy node for every original node.
    - Insert the copy node immediately after its original node.
- Step 2:
    - Set random pointers for copied nodes.
    - If original node's random points to X,
      copied node's random should point to X->next.
- Step 3:
    - Separate the interwoven list into:
        1. Original list
        2. Deep copied list
- Return the head of the copied list.

Time Complexity:
- O(n) : Insert copied nodes
- O(n) : Assign random pointers
- O(n) : Separate the two lists
- Overall: O(n)

Space Complexity:
- O(1) : No extra hash map used
- Overall: O(1)

Revision Keywords:
- Deep Copy
- Random Pointer
- Interweaving Technique
- Clone Linked List
- O(1) Space
- Linked List Hard
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
            return head;

        Node* temp = head;
        Node* curr;

        // Step 1: Insert copied nodes
        while(temp) {

            curr = temp->next;

            temp->next = new Node(temp->val);
            temp->next->next = curr;

            temp = curr;
        }

        // Step 2: Assign random pointers
        temp = head;

        while(temp) {

            temp->next->random =
                temp->random ? temp->random->next : NULL;

            temp = temp->next->next;
        }

        // Step 3: Separate copied list
        Node* dummy = new Node(-1);
        Node* tail = dummy;

        temp = head;

        while(temp) {

            tail->next = temp->next;

            temp->next = temp->next->next;

            tail = tail->next;

            temp = temp->next;
        }

        return dummy->next;
    }
};

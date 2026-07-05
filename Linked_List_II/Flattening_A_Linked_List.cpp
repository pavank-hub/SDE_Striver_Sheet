/*
GeeksforGeeks - Flattening a Linked List

Approach:
- Treat each bottom-linked list as a sorted linked list.
- Iteratively merge the current flattened list (l1)
  with the next vertical list (l2).
- Use a helper function similar to Merge Two Sorted Lists
  to merge two sorted bottom-linked lists.
- After merging:
    - Update l1 to the merged list.
    - Move l2 to the next vertical list.
- Continue until all vertical lists are merged into a
  single sorted bottom-linked list.
- Remove next links since the final list should only use
  bottom pointers.

Time Complexity:
- Merge costs
1st merge:
m+m=2m
2nd merge:
2m+m=3m
3rd merge:
3m+m=4m...
Last merge:
(n−1)m+m=nm
Total work:
2m+3m+4m+⋯+nm
=m(2+3+⋯+n)
=m(2n(n+1)−1)
- Overall: O(m*n*n)

Space Complexity:
- O(1) : Only pointer manipulation is used
- Overall: O(1)

Revision Keywords:
- Flatten Linked List
- Merge K Sorted Lists
- Bottom Pointer
- Iterative Merge
- Dummy Node
- Sorted Linked Lists
*/

class Solution {
public:

    Node* compareLL(Node* l1, Node* l2) {

        Node* t1 = l1;
        Node* t2 = l2;

        Node* dummy = new Node(-1);
        Node* tail = dummy;

        while(t1 && t2) {

            if(t1->data <= t2->data) {
                tail->bottom = t1;
                t1 = t1->bottom;
            }
            else {
                tail->bottom = t2;
                t2 = t2->bottom;
            }

            tail = tail->bottom;
        }

        tail->bottom = t1 ? t1 : t2;

        return dummy->bottom;
    }

    Node* flatten(Node* root) {

        if(!root || !root->next)
            return root;

        Node* l1 = root;
        Node* l2 = root->next;

        while(l1 && l2) {

            l1->next = NULL;

            Node* forwardHead = l2->next;
            l2->next = NULL;

            l1 = compareLL(l1, l2);

            l2 = forwardHead;
        }

        return l1;
    }
};

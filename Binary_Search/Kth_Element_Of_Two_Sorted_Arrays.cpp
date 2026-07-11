/*
GeeksforGeeks - K-th Element of Two Sorted Arrays

Approach:
- Apply Binary Search on the smaller array.
- Let:
    Px = elements taken from array a
    Py = elements taken from array b
- We need exactly k elements on the left side:
      Px + Py = k
- Partition both arrays and identify:
    l1 = largest element on left of a
    l2 = largest element on left of b
    r1 = smallest element on right of a
    r2 = smallest element on right of b
- Correct partition occurs when:
      l1 <= r2 && l2 <= r1
- At this point, the kth element is:
      max(l1, l2)
- If l1 > r2:
    move partition left.
- Else:
    move partition right.

Time Complexity:
- O(log(min(m, n))) : Binary search on the smaller array
- O(1)              : Constant work per iteration
- Overall: O(log(min(m, n)))

Space Complexity:
- O(1) : No extra data structures used
- Overall: O(1)

Revision Keywords:
- Binary Search
- Partition Logic
- Kth Element
- Two Sorted Arrays
- Smaller Array Search
- Hard Binary Search
*/

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {

        if(a.size() > b.size())
            return kthElement(b, a, k);

        int m = a.size();
        int n = b.size();

        int low  = max(0, k - n);
        int high = min(k, m);

        while(low <= high) {

            int Px = low + (high - low) / 2;
            int Py = k - Px;

            int l1 = (Px == 0) ? INT_MIN : a[Px - 1];
            int l2 = (Py == 0) ? INT_MIN : b[Py - 1];

            int r1 = (Px == m) ? INT_MAX : a[Px];
            int r2 = (Py == n) ? INT_MAX : b[Py];

            if(l1 <= r2 && l2 <= r1)
                return max(l1, l2);

            if(l1 > r2)
                high = Px - 1;
            else
                low = Px + 1;
        }

        return -1;
    }
};

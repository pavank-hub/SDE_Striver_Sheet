/*
LeetCode 4 - Median of Two Sorted Arrays

Approach:
- Apply Binary Search on the smaller array to minimize the search space.
- Partition both arrays such that:
    - Left half contains (m + n + 1) / 2 elements.
    - Right half contains the remaining elements.
- Let:
    - x1 = largest element on left side of nums1
    - x2 = largest element on left side of nums2
    - x3 = smallest element on right side of nums1
    - x4 = smallest element on right side of nums2
- Correct partition occurs when:
      x1 <= x4 && x2 <= x3
- Once the partition is valid:
    - Odd length  -> median = max(x1, x2)
    - Even length -> median = (max(x1,x2) + min(x3,x4)) / 2
- If partition is invalid:
    - x1 > x4 → move left
    - x2 > x3 → move right

Time Complexity:
- O(log(min(m, n))) : Binary search performed on the smaller array
- O(1)              : Constant work per iteration
- Overall: O(log(min(m, n)))

Space Complexity:
- O(1) : No extra data structures used
- Overall: O(1)

Revision Keywords:
- Binary Search
- Partition Logic
- Median of Two Arrays
- Left Half Right Half
- Smaller Array Search
- Hard Binary Search
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        // Binary Search on smaller array
        int low = 0;
        int high = m;

        while(low <= high) {

            int Px = low + (high - low) / 2;
            int Py = (m + n + 1) / 2 - Px;

            // Left half
            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int x2 = (Py == 0) ? INT_MIN : nums2[Py - 1];

            // Right half
            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];

            // Valid partition
            if(x1 <= x4 && x2 <= x3) {

                if((m + n) % 2 == 1)
                    return (double)max(x1, x2);

                return ((long long)max(x1, x2) +
                        min(x3, x4)) / 2.0;
            }

            // Move partition left
            if(x1 > x4)
                high = Px - 1;

            // Move partition right
            else
                low = Px + 1;
        }

        return -1;
    }
};

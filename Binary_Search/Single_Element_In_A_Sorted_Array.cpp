/*
LeetCode 540 - Single Element in a Sorted Array

Approach:
- Use Binary Search on the sorted array.
- Before the single element:
    - Pairs start at even indices.
      Example: [1,1,2,2,3,3]
                 ^ ^ ^ ^
- After the single element:
    - Pair alignment shifts and starts at odd indices.
- For each mid:
    - Check whether it belongs to the left or right pair.
    - Use index parity (even/odd) to determine which half
      contains the single element.
- If nums[mid] is different from both neighbors,
  it is the required answer.

Time Complexity:
- O(log n) : Binary search halves the search space every iteration
- Overall: O(log n)

Space Complexity:
- O(1) : Only variables are used
- Overall: O(1)

Revision Keywords:
- Binary Search
- Index Parity
- Pair Pattern
- Even-Odd Indices
- Sorted Array
- Single Element
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        int low = 0;
        int high = n - 1;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(nums[mid] == nums[mid - 1]) {

                if(mid % 2 == 0)
                    high = mid - 2;
                else
                    low = mid + 1;
            }

            else if(nums[mid] == nums[mid + 1]) {

                if(mid % 2 == 0)
                    low = mid + 2;
                else
                    high = mid - 1;
            }

            else
                return nums[mid];
        }

        return nums[low];
    }
};

/*
LeetCode 31 - Next Permutation

Approach:
- Traverse from right to left and find the first index (pivot)
  such that nums[pivot] < nums[pivot + 1].
- If no such index exists, the array is in descending order.
  Reverse the entire array to obtain the smallest permutation.
- Otherwise, find the rightmost element greater than nums[pivot].
- Swap nums[pivot] with that element.
- Reverse the suffix starting from pivot + 1 to get the next
  lexicographically greater permutation.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:

    void rev(int pivot, int n, vector<int>& nums) {
        int i = pivot + 1, j = n - 1;

        while(i < j) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int pivot = -1;

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) {
            rev(pivot, n, nums);
            return;
        }

        int replace = -1;

        for(int i = pivot + 1; i < n; i++) {
            if(nums[i] > nums[pivot])
                replace = i;
        }

        int temp = nums[replace];
        nums[replace] = nums[pivot];
        nums[pivot] = temp;

        rev(pivot, n, nums);
    }
};

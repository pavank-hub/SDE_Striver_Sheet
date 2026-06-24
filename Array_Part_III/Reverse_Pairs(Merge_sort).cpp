/*
LeetCode 493 - Reverse Pairs

Approach:
- Use Merge Sort to efficiently count reverse pairs while sorting the array.
- Divide the array recursively into two halves.
- Before merging, count reverse pairs across the two sorted halves.
- For each element in the left half, use a pointer (j) to count
  elements in the right half satisfying:
      nums[i] > 2 * nums[j]
- Since both halves are sorted, j only moves forward, making
  the counting step linear.
- After counting, merge the two sorted halves.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:

    void merge(int low, int mid, int high, vector<int>& nums) {

        int n1 = mid - low + 1;
        int n2 = high - mid;

        int L[n1], R[n2];

        // Fill left array
        int k = low;

        for(int i = 0; i < n1; i++) {
            L[i] = nums[k];
            k++;
        }

        // Fill right array
        for(int i = 0; i < n2; i++) {
            R[i] = nums[k];
            k++;
        }

        int i = 0, j = 0;
        k = low;

        while(i < n1 && j < n2) {

            if(L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            }
            else {
                nums[k] = R[j];
                j++;
            }

            k++;
        }

        while(i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }

        while(j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(int low, int high,
                   int& count,
                   vector<int>& nums) {

        if(low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(low, mid, count, nums);
        mergeSort(mid + 1, high, count, nums);

        // Count reverse pairs
        int j = mid + 1;

        for(int i = low; i <= mid; i++) {

            while(j <= high &&
                  nums[i] > 2LL * nums[j])

                j++;

            count += j - (mid + 1);
        }

        // Merge the sorted halves
        merge(low, mid, high, nums);
    }

    int reversePairs(vector<int>& nums) {

        int count = 0;

        mergeSort(0, nums.size() - 1,
                  count, nums);

        return count;
    }
};

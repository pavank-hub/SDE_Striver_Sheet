/*
GeeksforGeeks - Count Inversions

Approach:
- Use Merge Sort to efficiently count inversions while sorting the array.
- Divide the array into two halves recursively.
- Count inversions separately in the left and right halves.
- During the merge step:
    - If L[l] <= R[r], place L[l] into the array.
    - Otherwise, place R[r] and count all remaining elements
      in the left subarray as inversions because both halves
      are already sorted.
- Number of inversions added:
      n1 - l
  since every element from L[l] to L[n1-1] is greater than R[r].

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:

    void merge(vector<int>& arr, int low, int mid, int right, int& count) {

        int n1 = mid - low + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

        int k = low;

        for(int i = 0; i < n1; i++) {
            L[i] = arr[k];
            k++;
        }

        for(int i = 0; i < n2; i++) {
            R[i] = arr[k];
            k++;
        }

        int l = 0, r = 0;
        k = low;

        while(l < n1 && r < n2) {

            if(L[l] <= R[r]) {
                arr[k] = L[l];
                l++;
            }
            else {
                arr[k] = R[r];

                // Count inversions
                count += n1 - l;

                r++;
            }

            k++;
        }

        while(l < n1) {
            arr[k] = L[l];
            l++;
            k++;
        }

        while(r < n2) {
            arr[k] = R[r];
            r++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int low, int right, int& count) {

        if(low >= right)
            return;

        int mid = low + (right - low) / 2;

        mergeSort(arr, low, mid, count);
        mergeSort(arr, mid + 1, right, count);

        merge(arr, low, mid, right, count);
    }

    int inversionCount(vector<int>& arr) {

        int n = arr.size();

        int c = 0;

        mergeSort(arr, 0, n - 1, c);

        return c;
    }
};

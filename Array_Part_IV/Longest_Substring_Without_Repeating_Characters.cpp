/*
LeetCode 3 - Longest Substring Without Repeating Characters

Approach:
- Use Sliding Window with an index array to store the last
  occurrence of each character.
- Maintain two pointers:
    - left  -> start of current window
    - right -> end of current window
- If the current character has already appeared inside the
  current window, move left to one position after its last occurrence.
- Update the character's latest index.
- Track the maximum window length throughout the traversal.

Time Complexity: O(n)
Space Complexity: O(1)
(Fixed-size array of 256 characters)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> index(256, -1);

        int left = 0;
        int len = 0;

        for(int right = 0; right < s.size(); right++) {

            // Duplicate character found within current window
            if(index[s[right]] >= left)
                left = index[s[right]] + 1;

            // Update latest occurrence
            index[s[right]] = right;

            // Update maximum length
            len = max(len, right - left + 1);
        }

        return len;
    }
};

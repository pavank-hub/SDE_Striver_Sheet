/*
LeetCode 5 - Longest Palindromic Substring

Approach:
- Use the Expand Around Center technique.
- Every palindrome has a center:
    - Odd length palindrome  -> single character center
    - Even length palindrome -> two character center
- For each index:
    - Expand around (i, i) for odd length palindromes.
    - Expand around (i, i+1) for even length palindromes.
- While expanding:
    - Check if characters match.
    - Update the starting index and maximum length when a
      longer palindrome is found.
- Return the substring corresponding to the longest palindrome.

Time Complexity:
- O(n)   : Number of centers
- O(n)   : Expansion per center in the worst case
- Overall: O(n²)

Space Complexity:
- O(1) : Only variables are used
- Overall: O(1)

Revision Keywords:
- Expand Around Center
- Odd Length Palindrome
- Even Length Palindrome
- Two Pointers
- Longest Palindromic Substring
- String Medium
*/

class Solution {
public:

    int start = 0;
    int maxLen = 1;

    void expand(string& s, int l, int r) {

        while(l >= 0 &&
              r < s.length() &&
              s[l] == s[r]) {

            if(maxLen < (r - l + 1)) {
                maxLen = r - l + 1;
                start = l;
            }

            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {

        int n = s.size();

        for(int i = 0; i < n; i++) {

            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};

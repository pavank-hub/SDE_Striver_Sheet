/*
LeetCode 151 - Reverse Words in a String

Approach:
- Reverse the entire string.
- Traverse the reversed string and rewrite words starting
  from the beginning of the string.
- Skip extra spaces while copying characters.
- After copying a word:
    - Reverse that individual word to restore its order.
    - Add a single space.
- Use two pointers:
    - i : reads characters from the original string
    - r : writes characters to the compressed string
- Return the final string after removing the trailing space.

Time Complexity:
- O(n) : Reverse the entire string
- O(n) : Traverse and rewrite words
- O(n) : Reverse each word (total work across all words)
- Overall: O(n)

Space Complexity:
- O(1) : In-place modification of the string
- Overall: O(1)

Revision Keywords:
- Reverse Entire String
- Reverse Individual Words
- Two Pointers
- In-Place String Manipulation
- Remove Extra Spaces
- String Medium
*/

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());

        int n = s.length();

        int i = 0;
        int l = 0;
        int r = 0;

        while(i < n) {

            while(i < n && s[i] == ' ')
                i++;

            while(i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }

            if(l < r) {

                reverse(s.begin() + l, s.begin() + r);

                s[r++] = ' ';
                l = r;
            }
        }

        return s.substr(0, r - 1);
    }
};

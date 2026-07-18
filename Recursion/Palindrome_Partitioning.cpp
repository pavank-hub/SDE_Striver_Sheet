/*
LeetCode 131 - Palindrome Partitioning

Approach:
- Use Backtracking to generate all possible partitions of the string.
- Starting from idx, try every possible substring s[idx...i].
- Check whether the chosen substring is a palindrome.
- If it is a palindrome:
    - Add it to the current partition.
    - Recursively partition the remaining string from i + 1.
    - Backtrack by removing the chosen substring.
- When idx reaches the end of the string, store the current partition.

Time Complexity:
- O(2^n) : Number of possible partitioning patterns
- O(n)   : Palindrome checking / substring creation along a path
- Overall: O(n × 2^n)

Space Complexity:
- O(n) : Maximum recursion depth
- O(n) : Current partition can contain at most n strings
- Overall: O(n)
  (excluding output storage)

Revision Keywords:
- Backtracking
- Palindrome Partitioning
- Partition at Every Position
- Palindrome Check
- Choose → Explore → Backtrack
- String Partitioning
*/

class Solution {
public:

    vector<vector<string>> ans;

    bool isPalindrome(string& s, int l, int r) {

        while(l < r) {

            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void count(string& s,
               vector<string>& curr,
               int idx) {

        if(idx == s.length()) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < s.length(); i++) {

            if(isPalindrome(s, idx, i)) {

                curr.push_back(
                    s.substr(idx, i - idx + 1)
                );

                count(s, curr, i + 1);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> curr;

        count(s, curr, 0);

        return ans;
    }
};

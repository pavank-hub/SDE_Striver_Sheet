/*
LeetCode 13 - Roman to Integer

Approach:
- Traverse the Roman numeral string from left to right.
- Convert each Roman character into its corresponding integer value.
- If the current symbol has a smaller value than the next symbol:
    - Subtract its value from the answer.
    - This handles special cases such as:
        IV = 4
        IX = 9
        XL = 40
        XC = 90
        CD = 400
        CM = 900
- Otherwise, add its value to the answer.
- The final accumulated value is the integer representation.

Time Complexity:
- O(n) : Single traversal of the string
- O(1) : Value lookup for each character
- Overall: O(n)

Space Complexity:
- O(1) : Only variables are used
- Overall: O(1)

Revision Keywords:
- Roman Numerals
- Greedy Traversal
- Subtractive Notation
- Character Mapping
- String Easy
*/

class Solution {
public:

    int value(char c) {

        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;

        return 1000;
    }

    int romanToInt(string s) {

        int ans = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {

            if(i + 1 < n &&
               value(s[i]) < value(s[i + 1]))

                ans -= value(s[i]);

            else
                ans += value(s[i]);
        }

        return ans;
    }
};

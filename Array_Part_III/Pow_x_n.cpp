/*
LeetCode 50 - Pow(x, n)

Approach:
- Use Binary Exponentiation (Exponentiation by Squaring).
- If n is negative:
    - Invert x (x = 1/x)
    - Convert n to a positive number using long long
      to safely handle INT_MIN.
- While n > 0:
    - If n is even:
        - Square x
        - Halve n
    - If n is odd:
        - Multiply x into the result
        - Decrement n by 1
- This reduces the number of multiplications from O(n)
  to O(log n).

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;
        double res = 1.0;

        if(N < 0) {
            x = 1 / x;
            N *= -1;
        }

        while(N) {

            if(N % 2 == 0) {
                x *= x;
                N /= 2;
            }
            else {
                res *= x;
                N -= 1;
            }
        }

        return res;
    }
};

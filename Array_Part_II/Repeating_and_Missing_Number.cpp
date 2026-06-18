/*
InterviewBit - Repeat and Missing Number Array

Approach:
- Use the mathematical equations of Sum of N natural numbers
  and Sum of squares of N natural numbers.
- Let:
    x = repeating number
    y = missing number

- We know:
    x - y = actualSum - expectedSum

- Also:
    x² - y² = actualSquareSum - expectedSquareSum

- Using the identity:
    x² - y² = (x - y)(x + y)

- Find:
    x + y = (x² - y²) / (x - y)

- Solve the two equations:
    x - y = val1
    x + y = val2

- Obtain the repeating and missing numbers.

Time Complexity: O(n)
Space Complexity: O(1)
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {

    long long n = A.size();

    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;

    for(int i = 0; i < n; i++) {
        S += A[i];
        S2 += (long long)A[i] * (long long)A[i];
    }

    long long val1 = S - SN;      // x - y

    long long val2 = S2 - S2N;    // x² - y²

    val2 = val2 / val1;           // x + y

    long long x = (val1 + val2) / 2; // repeating number

    long long y = val2 - x;          // missing number

    return {(int)x, (int)y};
}

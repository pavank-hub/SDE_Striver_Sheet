/*
LeetCode 42 - Trapping Rain Water

Approach:
- Use the Two Pointer technique.
- Maintain:
    - l pointer from the left
    - r pointer from the right
    - lmax = maximum height seen from the left
    - rmax = maximum height seen from the right
    
- Process the smaller side.
- If height[l] <= height[r], then there exists a wall on the right
- that is at least as tall as height[l], so water at the left side
- depends only on lmax.
- Similarly, when height[r] < height[l], water at the right side
- depends only on rmax.

- Process the side with the smaller height because the trapped
  water at that position is limited by the smaller boundary.
- If current height is smaller than its corresponding max boundary:
    - Water trapped = maxBoundary - currentHeight
- Otherwise, update the boundary.
- Continue until both pointers meet.

Time Complexity:
- O(n) : Each index is visited at most once
- O(1) : Constant work per iteration
- Overall: O(n)

Space Complexity:
- O(1) : Only pointer and boundary variables are used
- Overall: O(1)

Revision Keywords:
- Two Pointers
- Trapping Rain Water
- Left Max
- Right Max
- Smaller Boundary Rule
- Space Optimized
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int l = 0;
        int r = n - 1;

        int lmax = 0;
        int rmax = 0;
        int total = 0;

        while(l < r) {

            if(height[l] <= height[r]) {

                if(lmax > height[l])
                    total += lmax - height[l];
                else
                    lmax = height[l];

                l++;
            }
            else {

                if(rmax > height[r])
                    total += rmax - height[r];
                else
                    rmax = height[r];

                r--;

            }
        }

        return total;
    }
};

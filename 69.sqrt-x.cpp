/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (33.48%)
 * Likes:    1268
 * Dislikes: 1857
 * Total Accepted:    540K
 * Total Submissions: 1.6M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */

// @lc code=start
class Solution {
   public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        int l = 1, r = x, mid = l + (r - l) / 2;

        while (true) {
            mid = l + (r - l) / 2;

            if (mid > x / mid) {
                r = mid - 1;
            } else {
                if (mid + 1 > x / (mid + 1)) {
                    return mid;
                }

                l = mid + 1;
            }
        }
    }
};
// @lc code=end

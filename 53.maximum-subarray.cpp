// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem53.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (46.11%)
 * Likes:    7786
 * Dislikes: 363
 * Total Accepted:    1M
 * Total Submissions: 2.2M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

/** Solution
 *  Select the p-th number of nums(0 < p < nums.size() - 1) 
 *  as the pivot. The maximum subarray[l,r] must
 *  lies in one of the following situations:
 *  (1). left to pivot (l <= r <= p)
 *  (2). rigt to pivot (p+1 <= l <=r)
 *  (3). cross the pivot (l < p < r)
 * 
 *  for (1) and (2) we can call maximum subarray method
 *  recursively.
 *  
 *  for (3), we need to find maximum subarray[i, p] and
 *  maximum subarray [p+1,j]
 * 
 *  Finally, return max((1), (2), (3))
 */

#include <vector>
using std::vector;

// @lc code=start

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int r = nums.size() - 1, l = 0;

        return maxSubArrayHelper(nums, l, r);
    }

    int maxSubArrayHelper(vector<int>& nums, const int l, const int r) {
        if (l == r)
        {
            return nums[l];
        }
        int p = (l + r) / 2;
        int lmax = maxSubArrayHelper(nums, l, p);
        int rmax = maxSubArrayHelper(nums, p+1, r);
        int cmax = crossingMaxSubArray(nums, l, r, p);

        if (lmax < rmax)
        {
            lmax = rmax;
        }

        if (lmax < cmax)
        {
            lmax = cmax;
        }
        
        
        return lmax;
    }

    int crossingMaxSubArray(vector<int>& nums, const int l, const int r, const int p) {
        int leftSum = INT_MIN, sum = 0;
        //int left;
        for (int i = p; i >= l; i--)
        {
            sum += nums[i];
            if (sum > leftSum)
            {
                leftSum = sum;
                //left = i;
            }
            
        }

        int rightSum = INT_MIN;
        sum = 0;
        //int right;
        for (int i = p + 1; i <= r; i++)
        {
            sum += nums[i];
            if (sum > rightSum)
            {
                rightSum = sum;
                //right = i;
            }
            
        }

        return (leftSum + rightSum);
        
    }
};
// @lc code=end


// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem215.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (54.12%)
 * Likes:    3657
 * Dislikes: 249
 * Total Accepted:    623.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
#include <vector>
using std::vector;
#include <algorithm>

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end());
        for (size_t i = 0; i < k - 1; i++)
        {
            std::pop_heap(nums.begin(), nums.end() - i);
        }
        return nums[0];
    }
};
// @lc code=end


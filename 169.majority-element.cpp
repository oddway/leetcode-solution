/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (58.03%)
 * Likes:    3250
 * Dislikes: 219
 * Total Accepted:    656.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

using std::sort;
using std::vector;

using std::cerr;
// @lc code=start
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2]; //this is always a majority element
    }
};
// @lc code=end

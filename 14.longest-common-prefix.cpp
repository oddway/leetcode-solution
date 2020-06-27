/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.10%)
 * Likes:    2498
 * Dislikes: 1836
 * Total Accepted:    744.8K
 * Total Submissions: 2.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 *
 *
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 * Note:
 *
 * All given inputs are in lowercase letters a-z.
 *
 */
#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        // return on empty input
        if (strs.empty()) {
            return "";
        }

        string& prefix = strs[0];
        int prefixEnd{__INT_MAX__}; /*common prefix end*/

        for (string& s : strs) {
            int i = 0;

            for (i = 0; i < prefix.size(); i++) {
                if (s[i] != prefix[i]) {
                    break;
                }
            }

            if (i < prefixEnd) {
                prefixEnd = i;
            }
        }

        return prefix.substr(0, prefixEnd);
    }
};
// @lc code=end

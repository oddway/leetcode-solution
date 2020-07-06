/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (34.19%)
 * Likes:    1567
 * Dislikes: 1900
 * Total Accepted:    666.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        if (haystack.size() < needle.size())
        {
            return -1;
        }
        

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            int p = i, j = 0;
            while (haystack[p] == needle[j])
            {
                if (j == needle.size() - 1)
                {
                    return i;
                }
                
                p++;
                j++;
            }
            
            
        }

        return -1;
    }
};
// @lc code=end

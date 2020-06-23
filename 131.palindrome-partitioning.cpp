// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (46.22%)
 * Likes:    1745
 * Dislikes: 64
 * Total Accepted:    222.7K
 * Total Submissions: 478.6K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 *
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 *
 */

// @lc code=start

/** Dyanmic Programming solution
 * 1.Iterating all possible n[1, s.length]. For each n,
 * Cut a head of the string with n-char long, if the head is
 * a palindrome, apply this method to the tail as
 * a new s recursively.
 *
 * Memorize verified palindrome to run faster.
 */

class Solution {
   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if (s.length() == 0) {
            return ret;
        }

        vector<string> path;

        partitionBt(s, 0, path, ret);

        return ret;
    }

    void partitionBt(const string &s, size_t index, vector<string> &path,
                     vector<vector<string>> &ret) {
        if (index == s.size()) {
            ret.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                partitionBt(s, i + 1, path, ret);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, size_t l, size_t r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

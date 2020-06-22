// @before-stub-for-debug-begin
#include <vector>
#include <string>

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
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {   
        vector<vector<string>> ans;

        for (int i = 1; i <= s.length(); i++)
        {
            auto subpartitions = partitionHelper(s, i);
            ans.insert(ans.end(), subpartitions.begin(), subpartitions.end());
        }

        return ans;
        
    }

    vector<vector<string>> partitionHelper(string s, int n)
    {   
        string head = s.substr(0, n);

        if (!isPalindrome(head))
        {
            return vector<vector<string>>(); // Stop this branch with an empty return.
        }

        vector<vector<string>> ans;

        if (s.length() == head.length())
        {   
            ans.push_back(vector<string>{head});
        }
        else
        {
            string tail = s.substr(n);
            for (int i = 1; i <= tail.length(); i++)
            {
                auto subpartitions = partitionHelper(tail, i);
                for (auto subpartition : subpartitions)
                {
                    subpartition.insert(subpartition.begin(), head);
                    ans.push_back(subpartition);
                }
            }
        }

        return ans;
    }

    bool isPalindrome(string s)
    {
        int len = s.length();

        if (len == 1)
        {
            return true;
        }

        for (int i = 0; i <= len / 2 - 1; i++)
        {
            if (s[i] != s[len - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

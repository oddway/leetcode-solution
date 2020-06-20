/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (74.18%)
 * Likes:    786
 * Dislikes: 78
 * Total Accepted:    34K
 * Total Submissions: 45.8K
 * Testcase Example:  '7'
 *
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 * 
 * Return a list of all possible full binary trees with N nodes.  Each element
 * of the answer is the root node of one possible tree.
 * 
 * Each node of each tree in the answer must have node.val = 0.
 * 
 * You may return the final list of trees in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 20
 * 
 * 
 */

/**
 * Idea:
 * 
 * Every full binary tree TTT with 3 or more nodes, has 2 children at its root.
 * Each of those children left and right [are themselves full binary trees].
 * 
 * 
 * /

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using std::vector;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int N)
    {
        if (N % 2 == 0)
        {
            return {};
        }

        vector<vector<TreeNode *>> dp(N + 1);
        dp[1].emplace_back(new TreeNode(0));
        for (int n{3}; n <= N; n += 2)
        {
            for (int i{1}; i != n; i += 2)
            {
                for (auto l : dp[i])
                {
                    for (auto r : dp[n - 1 - i])
                    {
                        dp[n].emplace_back(new TreeNode(0, treeCopy(l), treeCopy(r)));
                    }
                }
            }
        }
        return dp[N];
    }

    TreeNode* treeCopy(TreeNode* node) {
        if (!node) {return nullptr;}

        TreeNode* cpy = new TreeNode(node->val);
        cpy->left = treeCopy(node->left);
        cpy->right = treeCopy(node->right);

        return cpy;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start

class Solution {
public:
    bool isValid(string s) {
        //a stack for parentheses
        vector<char> parentheseStack;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                parentheseStack.push_back(c);
            }

            switch (c) {
            case ')':
                if (parentheseStack.empty() || parentheseStack.back() != '(') {
                    return false;
                }

                parentheseStack.pop_back();
                break;

            case '}':
                if (parentheseStack.empty() || parentheseStack.back() != '{') {
                    return false;
                }
                parentheseStack.pop_back();
                break;

            case ']':
                if (parentheseStack.empty() || parentheseStack.back() != '[') {
                    return false;
                }
                parentheseStack.pop_back();
                break;
            default:
                break;
            }
        }

        return parentheseStack.empty();
    }
};
// @lc code=end


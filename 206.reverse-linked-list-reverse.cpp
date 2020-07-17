// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem206.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (61.33%)
 * Likes:    4542
 * Dislikes: 90
 * Total Accepted:    1M
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 *
 *
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        return reverseListRec(head, nullptr);
    }

    ListNode* reverseListRec(ListNode* head, ListNode* prev) {
        if (head == nullptr) {
            head->next = prev;
            return head;
        }

        ListNode* next = head->next;
        head->next = prev;
        return reverseListRec(next, head);
    }
};
// @lc code=end

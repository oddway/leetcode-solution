// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem811.h"

using namespace std;
// @before-stub-for-debug-end

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <unordered_map>
using std::unordered_map;



/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 *
 * https://leetcode.com/problems/subdomain-visit-count/description/
 *
 * algorithms
 * Easy (69.13%)
 * Likes:    477
 * Dislikes: 628
 * Total Accepted:    83.9K
 * Total Submissions: 121.1K
 * Testcase Example:  '["9001 discuss.leetcode.com"]'
 *
 * A website domain like "discuss.leetcode.com" consists of various subdomains.
 * At the top level, we have "com", at the next level, we have "leetcode.com",
 * and at the lowest level, "discuss.leetcode.com". When we visit a domain like
 * "discuss.leetcode.com", we will also visit the parent domains "leetcode.com"
 * and "com" implicitly.
 * 
 * Now, call a "count-paired domain" to be a count (representing the number of
 * visits this domain received), followed by a space, followed by the address.
 * An example of a count-paired domain might be "9001 discuss.leetcode.com".
 * 
 * We are given a list cpdomains of count-paired domains. We would like a list
 * of count-paired domains, (in the same format as the input, and in any
 * order), that explicitly counts the number of visits to each subdomain.
 * 
 * 
 * Example 1:
 * Input: 
 * ["9001 discuss.leetcode.com"]
 * Output: 
 * ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
 * Explanation: 
 * We only have one website domain: "discuss.leetcode.com". As discussed above,
 * the subdomain "leetcode.com" and "com" will also be visited. So they will
 * all be visited 9001 times.
 * 
 * 
 * 
 * 
 * Example 2:
 * Input: 
 * ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
 * Output: 
 * ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1
 * intel.mail.com","951 com"]
 * Explanation: 
 * We will visit "google.mail.com" 900 times, "yahoo.com" 50 times,
 * "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will
 * visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and
 * "org" 5 times.
 * 
 * 
 * 
 * Notes: 
 * 
 * 
 * The length of cpdomains will not exceed 100. 
 * The length of each domain name will not exceed 100.
 * Each address will have either 1 or 2 "." characters.
 * The input count in any count-paired domain will not exceed 10000.
 * The answer output can be returned in any order.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domainCount;
        string countStr;
        string domain;

        for(auto &cpdomain : cpdomains) {
            istringstream domainInput(cpdomain);
            domainInput >> countStr;
            int count = std::stoi(countStr);

            domainInput >> domain;

            while(domain.find('.') != string::npos) {
                if (domainCount.find(domain) != domainCount.end()) {
                    domainCount[domain] += count;
                } else
                {
                    domainCount.emplace(domain, count);
                }

                domain = domain.substr(domain.find('.') + 1);
            }

            if (domainCount.find(domain) != domainCount.end()) {
                    domainCount[domain] += count;
                } else
                {
                    domainCount.emplace(domain, count);
                }
        }

        vector<string> ans;
        for(auto countPair : domainCount) {
            string res;
            res += std::to_string(countPair.second) + " " + countPair.first;
            ans.push_back(res);
        }

        return ans;
    }
};
// @lc code=end


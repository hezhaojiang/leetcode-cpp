/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include<iostream>
#include<vector>
#include<set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()) return false;
        multiset<long> numlist{nums[0]};
        for(int i = 1; i < nums.size(); i++)
        {
            if(i > k) numlist.erase(numlist.find(nums[i-k-1]));
            auto lower = numlist.lower_bound(nums[i]);
            if ((lower != numlist.end() && *lower - t <= nums[i]) || (lower != numlist.begin() && *(--lower) + t >= nums[i]))
                return true;
            numlist.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end
int main(void)
{
    Solution solve;
    bool res = solve.containsNearbyAlmostDuplicate(vector<int> {1,5,9,1,5,9}, 2, 3);
    cout << res << endl;
    return 0;
}


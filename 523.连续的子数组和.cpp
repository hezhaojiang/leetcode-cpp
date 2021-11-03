/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
using llint = long long int;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<llint> sums(n + 1, 0);
        unordered_map<int, int> rest;
        rest[0] = 0;
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
            int div = sums[i + 1] % k;
            if (rest.count(div)) {
                if (i - rest[div] > 0) return true;
            } else {
                rest[div] = i + 1;
            }
        }
        return false;
    }
};


int main() {
    char c = '\n';
    int n;
    do scanf("%c", &c);
    while (c != '[');
    vector<int> nums;
    do {
        scanf("%d", &n);
        nums.push_back(n);
        scanf("%c", &c);
    } while (c != ']');
    int k = 0;
    scanf("%d", &k);
    Solution solve;
    bool res = solve.checkSubarraySum(nums, k);
    if (res) cout << "true" << endl;
    else cout << "false" << endl;
}
#define main mian2
// @lc code=end

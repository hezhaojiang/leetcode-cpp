/*
 * @lc app=leetcode.cn id=1414 lang=cpp
 *
 * [1414] 和为 K 的最少斐波那契数字数目
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib{1, 2};
        int twosum = 3;
        while (twosum < k) {
            int t = fib.back();
            fib.push_back(twosum);
            twosum += t;
        }
        fib.push_back(twosum);
        int res = 0;
        while (k != 0) {
            k -= *(upper_bound(fib.begin(), fib.end(), k) - 1);
            res++;
        }
        return res;
    }
};
// @lc code=end


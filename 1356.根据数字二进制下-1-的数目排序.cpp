/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
bool cmp(int a, int b) {
    if (__builtin_popcount(a) < __builtin_popcount(b)) return true;
    if (__builtin_popcount(a) == __builtin_popcount(b)) return a < b;
    return false;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
// @lc code=end


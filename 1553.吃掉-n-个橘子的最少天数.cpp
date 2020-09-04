/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 *
 * [1553] 吃掉 N 个橘子的最少天数
 */
#include<unordered_map>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    unordered_map<int, int> hash;
public:
    int minDays(int n) {
        if (n <= 1) return n;
        if (hash.find(n) != hash.end()) return hash[n];
        hash[n] = min(minDays(n / 2) + n % 2, minDays(n / 3) + n % 3) + 1;
        return hash[n];
    }
};
// @lc code=end


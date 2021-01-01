/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        for (int i = 0; i < N; i++) {
            if (flowerbed[i]) continue;
            if (i > 0 && flowerbed[i - 1]) continue;
            if (i + 1 < N && flowerbed[i + 1]) continue;
            flowerbed[i] = 1;
            n--;
        }
        if (n <= 0) return true;
        else return false;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int N) {
        if (N == 0 || N == 1) return N;
        int onePre = 0, twoPre = 1, Cur;
        //return fib(N - 1) + fib(N - 2);
        for (int i = 0; i < N; i++) {
            Cur = onePre + twoPre;
            twoPre = onePre;
            onePre = Cur;
        }
        return Cur;
    }
};
// @lc code=end


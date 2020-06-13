/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        int mid = start + (end - start) / 2;
        while (start + 1 < end)
        {
            int ret = guess(mid);
            if (ret == 0) return mid;
            else if (ret > 0) start = mid;
            else end = mid;
            mid = start + (end - start) / 2;
        }
        return (0==guess(start))?start:end;
    }
};
// @lc code=end


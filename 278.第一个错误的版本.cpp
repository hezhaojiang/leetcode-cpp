/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */
#include<iostream>
using namespace std;
// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int mid = start + (end - start) / 2;
        while(start + 1 < end)
        {
            if(isBadVersion(mid)) end = mid;
            else start = mid;
            mid = start + (end - start) / 2;
        }
        if(isBadVersion(start)) return start;
        else return end;
    }
};
// @lc code=end


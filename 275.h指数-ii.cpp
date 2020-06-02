/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H指数 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int siz = citations.size();
        int left = 0;
        int right = citations.size();
        int mid = (left + right) / 2;
        while(mid < right)
        {
            if(citations[mid] == siz - mid) return citations[mid];
            else if(citations[mid] > siz - mid) right = mid;
            else left = mid + 1;
            mid = (left + right) / 2;
        }
        return siz - left;
    }
};
// @lc code=end


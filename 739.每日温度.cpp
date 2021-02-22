/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int N = T.size();
        vector<int> res(N, 0);
#if 0
        vector<int> lst(105, INT_MAX);
        for (int i = N - 1; i >= 0; i--) {
            int temperat = T[i];
            auto next = min_element(lst.begin() + temperat  + 1, lst.end());
            if (*next != INT_MAX) res[i] = *next - i;
            lst[temperat] = i;
        }
#endif
        vector<int> st;
        for (int i = 0; i < N; i++) {
            while (!st.empty() && T[st.back()] < T[i]) {
                res[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        while (!st.empty()) {
            res[st.back()] = 0;
            st.pop_back();
        }
        return res;
    }
};
// @lc code=end

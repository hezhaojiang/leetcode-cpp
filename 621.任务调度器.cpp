/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int N = tasks.size();
        vector<int> count(26);
        for (auto t : tasks) count[t - 'A']++;
        sort(count.begin(), count.end());
        int index = 25, need = (n + 1) * (count[25] - 1);
        while (index >= 0 && count[index--] == count[25]) need++;
        return max(N, need);
    }
};
// @lc code=end


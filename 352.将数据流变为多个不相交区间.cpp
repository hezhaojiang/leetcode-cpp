/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
// @lc code=start
class SummaryRanges {
private:
    set<vector<int>> s;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {}

    void addNum(int val) {
        auto it = lower_bound(s.begin(), s.end(), vector<int>{val, val}, [](auto& a, auto& b) { return a[0] < b[0]; });
        int start = val, end = val;
        if (it != s.begin() && (*--it)[1] + 1 < val) it++;
        while (it != s.end() && val + 1 >= (*it)[0] && val - 1 <= (*it)[1]) {
            start = min(start, (*it)[0]);
            end = max(end, (*it)[1]);
            it = s.erase(it);
        }
        s.insert(it, vector<int>{start, end});
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

int main() {
    SummaryRanges summary;
    summary.addNum(1);
    summary.addNum(3);
    return 0;
}

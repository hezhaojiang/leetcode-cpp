/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stoneq;
        for (int s : stones) stoneq.push(s);
        
        while (stoneq.size() > 1) {
            int stone1 = stoneq.top();
            stoneq.pop();
            int stone2 = stoneq.top();
            stoneq.pop();
            if (stone1 > stone2) stoneq.push(stone1 - stone2);
            else if (stone1 < stone2) stoneq.push(stone2 - stone1);
        }
        if (stoneq.empty()) return 0;
        else return stoneq.top();
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<int> stones{2,7,4,1,8,1};
    solve.lastStoneWeight(stones);
    return 0;
}

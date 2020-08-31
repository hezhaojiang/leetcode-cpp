/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int dfs(vector<vector<int>>& rooms, int roomNo) {
        if (!rooms[roomNo].empty() && rooms[roomNo].back() == -1) return 0;
        int openCount = 1;
        rooms[roomNo].push_back(-1);
        for (auto & key : rooms[roomNo])
            if(key != -1) openCount += dfs(rooms, key);
        return openCount;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int roomCount = rooms.size();
        if (roomCount == 0) return true;
        int openCount = dfs(rooms, 0);
        return openCount == roomCount;
    }
};
// @lc code=end
int main() {
    Solution solve;
    vector<vector<int>> rooms {
        vector<int>{1},
        vector<int>{2},
        vector<int>{3},
        vector<int>{ }
    };
    bool res = solve.canVisitAllRooms(rooms);
    return 0;
}

/*
 * @lc app=leetcode.cn id=1203 lang=cpp
 *
 * [1203] 项目管理
 */
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> topologicalSort(vector<vector<int>> &adj, vector<int> &inDegree, int n) {
        vector<int> res;
        queue<int> queue;

        // 将入度为 0 的元素入队列
        for (int i = 0; i < n; i++) if (inDegree[i] == 0) queue.push(i);

        // 依次遍历队列中的元素
        while (!queue.empty()) {
            int front = queue.front();
            queue.pop();
            res.push_back(front);
            for (int successor : adj[front]) {
                // 将入度为 0 的元素插入队列
                if (--inDegree[successor] == 0) queue.push(successor);
            }
        }

        // 能遍历完所有元素才返回遍历结果，否则返回空数组
        if (res.size() == n) return res;
        else return {};
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // 第 1 步：数据预处理，给没有归属于一个组的项目编上组号
        for (int i = 0; i < group.size(); i++) if (group[i] == -1) group[i] = m++;

        // 第 2 步：实例化组和项目的邻接表
        vector<vector<int>> groupsAdjacencylist(m);  // 组的邻接表
        vector<vector<int>> itemsAdjacencylist(n);   // 项目的邻接表

        // 第 3 步：建图和统计入度表
        vector<int> groupsIndegree(m, 0);   // 组的入度表
        for (int i = 0; i < group.size(); i++) {
            int currentGroup = group[i];
            for (auto & beforeItem : beforeItems[i]) {
                int beforeGroup = group[beforeItem];
                if (beforeGroup != currentGroup) {
                    groupsAdjacencylist[beforeGroup].push_back(currentGroup);
                    groupsIndegree[currentGroup]++;
                }
            }
        }

        vector<int> itemsIndegree (n, 0);   // 项目的入度表
        for (int i = 0; i < group.size(); i++) {
            for (auto & beforeItem : beforeItems[i]) {
                itemsAdjacencylist[beforeItem].push_back(i);
                itemsIndegree[i]++;
            }
        }

        // 第 4 步：得到组和项目的拓扑排序结果
        vector<int> && groupsList = topologicalSort(groupsAdjacencylist, groupsIndegree, m);
        vector<int> && itemsList = topologicalSort(itemsAdjacencylist, itemsIndegree, n);
        if (groupsList.empty() || itemsList.empty()) return {};

        // 第 5 步：根据项目的拓扑排序结果，项目到组的多对一关系，建立组到项目的一对多关系
        // key：组 value：在同一组的项目列表
        unordered_map<int, vector<int>> groups2Items;
        for (int item : itemsList) groups2Items[group[item]].push_back(item);

        // 第 6 步：把组的拓扑排序结果替换成为项目的拓扑排序结果
        vector<int> res;
        for (int groupId : groupsList) {
            vector<int> &items = groups2Items[groupId];
            for (auto &item : items) res.push_back(item);
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> visited;           /* 检测是否已遍历过 */
    vector<vector<int>> edges;     /* 记录先修课程 */
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses);
        vector<vector<int>> edges(numCourses);
        queue<int> Q;
        vector<int> CourseOrder;
        int LearnCources = 0;

        /* 构建邻接表，表示每个顶点连接的下一个顶点 */
        for (auto req : prerequisites) {
            in_degree[req[0]]++;
            edges[req[1]].push_back(req[0]);
        }

        /* 将入度为 0 的点入栈 */
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                Q.push(i);
                CourseOrder.push_back(i);
                LearnCources++;
            }
        }

        /* 学习每一个课程，并将学过的课程的下一门课程的入度减 1 */
        while (!Q.empty()) {
            for (auto edge : edges[Q.front()]) {
                if(--in_degree[edge] == 0) {
                    Q.push(edge);
                    CourseOrder.push_back(edge);
                    LearnCources++;
                }
            }
            Q.pop();
        }  

        if (LearnCources == numCourses) return CourseOrder;
        else return vector<int>{};
    }
};
// @lc code=end


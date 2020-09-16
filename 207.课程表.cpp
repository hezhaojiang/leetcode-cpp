/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
private:
    bool can = true;
    vector<int> visited;           /* 检测是否已遍历过 */
    vector<vector<int>> edges;     /* 记录先修课程 */
    bool findCircle(int u) {
        if (visited[u] == 1) return true;
        else if (visited[u] == 2) return false;
        visited[u] = 1;
        for (int v : edges[u]) if (findCircle(v)) return true;
        visited[u] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
#ifdef DFS
        vector<int> in_degree(numCourses);
        vector<vector<int>> edges(numCourses);
        queue<int> Q;
        int LearnCources = 0;

        /* 构建邻接表，表示每个顶点连接的下一个顶点 */
        for (auto req : prerequisites) {
            in_degree[req[1]]++;
            edges[req[0]].push_back(req[1]);
        }

        /* 将入度为 0 的点入栈 */
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                Q.push(i);
                LearnCources++;
            }
        }

        /* 学习每一个课程，并将学过的课程的下一门课程的入度减 1 */
        while (!Q.empty()) {
            for (auto edge : edges[Q.front()]) {
                if(--in_degree[edge] == 0) {
                    Q.push(edge);
                    LearnCources++;
                }
            }
            Q.pop();
        }
            

        if (LearnCources == numCourses) return true;
        return false;
#endif
        edges.resize(numCourses);
        visited.resize(numCourses);

        for (const auto & info: prerequisites) edges[info[0]].push_back(info[1]);

        for (int i = 0; i < numCourses && can; ++i)
            if (!visited[i] && findCircle(i)) return false;
        return true;
    }
};
// @lc code=end


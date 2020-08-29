/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */
#include<vector>
using namespace std;
// @lc code=start
class UnionFind{
private:
    vector<int> parent;
    vector<int> size;
    int count;
public:
    UnionFind(vector<vector<int>>& M){
        int n = M.size();
        parent.resize(n + 1);
        size.resize(n + 1);
        count = n;
        for(int i = 1; i < n + 1; i++){
            parent[i] = i;
            size[i] = 1;  
        }
                
    }
    int find(int p){
        while(p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    void connect(int p, int q){
        int rootp = find(p);
        int rootq = find(q);
        if(rootp == rootq) return;
        if(size[rootp] < size[rootq]){
            parent[rootp] = rootq;
            size[rootq] += size[rootp];
        }
        else{
            parent[rootq] = rootp;
            size[rootp] += size[rootq];
        }        
        count--;
    }
    int getcount(){
        return count;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(edges);        
        for(int i = 0; i < n; i++){
            int rootp = uf.find(edges[i][0]);
            int rootq = uf.find(edges[i][1]);
            if(rootp == rootq) return edges[i];
            uf.connect(rootp, rootq);
        }
        return {};
    }
};
// @lc code=end


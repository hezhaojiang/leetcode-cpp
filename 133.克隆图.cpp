/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldNode2NewNode) {
        // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
        if (oldNode2NewNode.find(node) != oldNode2NewNode.end()) 
            return oldNode2NewNode[node];

        // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
        Node* cloneNode = new Node(node->val);

        // 哈希表存储
        oldNode2NewNode[node] = cloneNode;

        for (auto& neighbor: node->neighbors) {
            cloneNode->neighbors.emplace_back(dfs(neighbor, oldNode2NewNode));
        }
        return cloneNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldNode2NewNode;
        if (!node) return node;
        return dfs(node, oldNode2NewNode);
    }
};
// @lc code=end


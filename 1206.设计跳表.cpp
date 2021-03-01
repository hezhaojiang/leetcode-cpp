/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 *
 * [1206] 设计跳表
 */
#include<random>
using namespace std;
// @lc code=start
struct Node {
    int val;
    Node *right, *down;
    Node(int v = 0, Node *r = nullptr, Node *d = nullptr) : val(v), right(r), down(d) {}
};

class Skiplist {
private:
    int level = 0;
    Node *head = nullptr;

public:
    Skiplist() {}

    bool search(int target) {
        Node *node = head;
        while (node) {
            while (node->right && node->right->val <= target) node = node->right;
            if (node->val == target) return true;
            node = node->down;
        }
        return false;
    }

    void add(int num) {
        int rlevel = 1;
        while (rlevel <= level && (rand() & 1) == 0) rlevel++;
        if (rlevel > level) {
            level = rlevel;
            head = new Node(INT_MIN, nullptr, head);
        }
        Node *node = head, *last = nullptr;
        for (int l = level; l > 0; l--) {
            while (node->right && node->right->val < num) node = node->right;
            if (l <= rlevel) {
                node->right = new Node(num, node->right);
                if (last) last->down = node->right;
                last = node->right;
            }
            node = node->down;
        }
    }

    bool erase(int num) {
        Node *node = head;
        bool res = false;
        for (int l = level; l > 0; l--) {
            while (node->right && node->right->val < num) node = node->right;
            if (node->right && node->right->val == num) {
                res = true;
                Node *del = node->right;
                node->right = del->right;
                delete del;
            }
            node = node->down;
        }
        return res;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end

int main()
{
    Skiplist l;
    l.add(1);
    l.add(2);
    l.add(3);
    l.search(0);
    l.add(4);
    l.search(1);
    l.erase(0);
    l.erase(1);
    l.search(1);
    return 0;
}

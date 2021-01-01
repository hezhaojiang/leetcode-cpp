/*
 * @lc app=leetcode.cn id=1352 lang=cpp
 *
 * [1352] 最后 K 个数的乘积
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class ProductOfNumbers {
private:
    vector<int> pre_product;
public:
    ProductOfNumbers() {
        pre_product = {};
}
    
    void add(int num) {
        if (num == 0) return pre_product.clear();
        if (pre_product.empty()) pre_product.push_back(num);
        else pre_product.push_back(pre_product.back() * num);
    }
    
    int getProduct(int k) {
        int n = pre_product.size();
        if (k > n) return 0;
        else if (k == n) return pre_product[n - 1];
        else return pre_product[n - 1] / pre_product[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

/* Test Main */
int main(void)
{
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]
    productOfNumbers.getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
    productOfNumbers.getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
    productOfNumbers.getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
    productOfNumbers.add(8);        // [3,0,2,5,4,8]
    productOfNumbers.getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32 
    return 0;
}

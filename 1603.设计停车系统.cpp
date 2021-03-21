/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */
#include <vector>
using namespace std;
// @lc code=start
class ParkingSystem {
private:
    vector<int> cars;

public:
    ParkingSystem(int big, int medium, int small) {
        cars.resize(4, 0);
        cars[1] = big;
        cars[2] = medium;
        cars[3] = small;
    }

    bool addCar(int carType) { return cars[carType]-- > 0; }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

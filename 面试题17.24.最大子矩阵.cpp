#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0) return {};
        int N = matrix[0].size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        dp[1][1] = matrix[0][0];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                dp[i + 1][j + 1] = matrix[i][j] + dp[i][j + 1];
            }
        }
        int maxMatrix = INT_MIN;
        vector<int> result(4,0);
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
        for (r1 = 0; r1 < M; r1++) {
            for (r2 = r1; r2 < M; r2++) {
                vector<int> dpline(N, 0);
                for (int i = 0; i < N; i++) dpline[i] = dp[r2 + 1][i + 1] - dp[r1][i + 1];
                int Matrix = 0;
                c1 = 0;
                for (c2 = 0; c2 < N; c2++) {
                    if (Matrix > 0) Matrix += dpline[c2];
                    else {
                        Matrix = dpline[c2];
                        c1 = c2;
                    }
                    if (Matrix > maxMatrix) {
                        maxMatrix = Matrix;
                        result[0] = r1;
                        result[1] = c1;
                        result[2] = r2;
                        result[3] = c2;
                    }
                }
            }
        }
        return result; 
    }
};

/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<int>> matrix;
    matrix.push_back({9,-8,1,3,-2});
    matrix.push_back({-3,7,6,-2,4});
    matrix.push_back({6,-4,-4,8,-7});
    solve.getMaxMatrix(matrix);
    return 0;
}
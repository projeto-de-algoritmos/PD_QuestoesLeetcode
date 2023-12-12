#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            // cout << "NUM: " << nums[i] << ' ';
            sum += nums[i];
        }

        if (sum % 2) {
            // cout << "\nsum: " << sum << '\n';
            return false;
        }

        int m = (sum / 2) + 1;
        int knapsack[n + 1][m];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                knapsack[i][j] = 0;
            }
        }

        for (int i = 0; i <= n; i++) {
            knapsack[i][0] = 1; 
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j < m; j++) {
                if (nums[i] > j) {
                    knapsack[i][j] = knapsack[i + 1][j];
                } else {
                    knapsack[i][j] = knapsack[i + 1][j] || knapsack[i + 1][j - nums[i]];
                }
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << knapsack[i][j] << ' ';
        //     }
        // }
        return knapsack[0][m - 1];
    }
};

int main () {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    bool ans = solution.canPartition(nums);
    cout << (ans ? "YES\n" : "NO\n");
    return 0;
}
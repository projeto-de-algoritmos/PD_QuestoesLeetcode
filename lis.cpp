#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> size(n);
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            size[i] = 1;
            prev[i] = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && size[j] + 1 > size[i]) {
                    size[i] = size[j] + 1;
                    prev[i] = j;
                } 
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (size[i] > ans) {
                ans = size[i];
            }
        }

        return ans;
    }
};

int main() {
    int n; cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    Solution solution;
    int ans = solution.lengthOfLIS(input);
    cout << ans << '\n';
    return 0;
}
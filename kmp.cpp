#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string aux = s + '#' + rev;
        auto n = aux.length();
        vector<int> kmp(n);
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (aux[index] == aux[i]) {
                kmp[i] = kmp[i - 1] + 1;
                ++index;
            } else {
                index = kmp[i - 1];
                while (index > 0 && aux[index] != aux[i]) {
                    index = kmp[index - 1];
                }
                if (aux[index] == aux[i]) {
                    ++index;
                }
                kmp[i] = index;
            }
        }

        string ans = rev;
        for (int i = kmp[n - 1]; i < s.length(); i++) {
            ans += s[i];
        }
        // cout << '\n' << aux << '\n';
        return ans;
    }
};

int main() {
    string s; cin >> s;

    Solution solution;
    string ans = solution.shortestPalindrome(s);
    cout << ans << '\n';
    return 0;
}
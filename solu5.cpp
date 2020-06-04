#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int maxlen = 1100;
        //int dp[maxlen][maxlen];
        char dp[maxlen][maxlen] ={0};
        int i, j, L;
        int len = s.length();
        int left = 0, right = 0;
        int ans = 1;
        //边界
        for (i = 0; i < len; i++) {
            dp[i][i] = 1;
            if (i < len -1 ) {
                if (s[i] == s[i+1]) {
                    dp[i][i+1] = 1;
                    ans = 2;
                    left = i;
                    right = i+1;
                }
            }
        }
        //动态规划
        for(L=3; L <= len; ++L) {
            for(i=0; i+L-1 < len; i++) {
                j = i + L -1;
                if(s[i] == s[j] && dp[i+1][j-1]==1) {
                    dp[i][j] = 1;
                    left = i;
                    right = j;
                    ans = L;
                }
            }
        }
        return s.substr(left,ans);
    }
};

int main() {
    Solution s;
    string inputs;
    cin >> inputs;
    string res = s.longestPalindrome(inputs);
    cout << res << endl;
}
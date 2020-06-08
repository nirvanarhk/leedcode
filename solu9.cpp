#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int inputx = x;
        int y = 0;
        int res = 0;
        if(x < 0) {
            return false;
        }
        while(x != 0) {
            y = x % 10;
            x = x / 10;
            if (res > INT_MAX/10 || (res == INT_MAX/10 && y > INT_MAX%10))
            {
                return false;
            } else if (res < INT_MIN/10 || (res == INT_MIN/10 && y <= INT_MIN%10)) {
                return false;
            }
            res = res * 10 + y;
        }
        //cout << res << endl;
        if (res == inputx) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    bool res = s.isPalindrome(2147483647);
    cout << res << endl;
}
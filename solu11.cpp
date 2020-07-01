#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0, j = len -1;
        int hleft = 0;
        int hright = 0;
        int h = 0;
        int area = 0;
        int maxarea = 0;
        while (i < j) {
            hleft = height[i];
            hright = height[j];
            h = hleft > hright? hright:hleft;
            area = h * (j - i);
            if (area > maxarea) {
                maxarea = area;
            }
            if (hleft < hright) {
                i += 1;
            } else {
                j -= 1;
            }
        }
        return maxarea;
    }
};

int main() {
    Solution s;
    int a[9] = {1,8,6,2,5,4,8,3,7};
    vector<int> t(a,a+9);
    int res = s.maxArea(t);
    cout << res << endl;
}
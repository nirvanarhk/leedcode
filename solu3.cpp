#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if(s.length() == 0)
            return res;
        // 创建HashMap，用来保存字符与位置之间的对应关系
        map<char, int> namemap;
        // 初始化左指针和右指针，并遍历字符串
        for(int left = 0, right = 0; right < s.length(); right++){
            // 判断右指针指向的字符是否出现过
            char c = s.at(right);
            if(namemap.find(c) != namemap.end()){
                // 确定左指针的位置
                int x = namemap[c];
                left = left > x + 1 ? left:(x+1);
            }
            // 对于第一次出现的字符，保存该字符的位置；对于多次出现的字符，更新该字符出现的位置
            namemap[c] = right;
            // 更新窗口的大小，保存最大的窗口大小
            res = res > right - left + 1? res : right - left + 1;
        }
        return res;
    }
};

int main()
{
    Solution t;
    int maxlen = t.lengthOfLongestSubstring("testtest");
    cout << maxlen << endl;
}


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        int maxcol = numRows;
        if (numRows > 1) {
            maxcol = (len + 2*numRows -3)/(2*numRows-2);
        }
        string outstr = s;
        int outstrlen = 0;
        // row 0
        for(int j = 0; j <= maxcol; j++) {
            int k = j * 2 * (numRows - 1);
            if (k < len) {
                //cout << s[k];
                outstr[outstrlen++] = s[k];
            }
        }
        // row 1~numRow-2
        for(int i = 1; i < numRows -1; i++) {
            for (int j = 0; j <= maxcol; j++) {
                int k = j * 2 * (numRows - 1);
                if (j == 0) {
                    //cout << s[i];
                    outstr[outstrlen++] = s[i];
                }
                else {
                    if (k-i  < len){
                        //cout << s[k-i];
                        outstr[outstrlen++] = s[k-i];
                    }
                    if(k+i  < len) {
                        //cout << s[k+i];
                        outstr[outstrlen++] = s[k+i];
                    }
                }
            }
        }
        // numRow -1
        for(int j = 0; j <= maxcol; j++) {
            int k = j * 2 * (numRows - 1) + numRows -1;
            if (k < len) {
                //cout << s[k];
                outstr[outstrlen++] = s[k];
            }
        }
        //cout << endl;
        //outstr[outstrlen++] = '\0';
        //cout << outstrlen << endl;
        return outstr;
        
    }
};

int main() {
    Solution s;
    string res = s.convert("PAYPALISHIRING", 1);
    cout << res << endl;
}
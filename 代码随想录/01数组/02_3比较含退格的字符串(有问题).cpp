#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        while (i >= 0 || j >= 0) {
            int isMoveS = false;
            int isMoveT = false;
            if (s[i] == '#') {
                if (s[i - 1] != '#')
                {
                    i-=2;//前一个是字母，要消除
                }
                else {//前一个也是#，消除这个和它之前的
                    s[i - 2] = '#';
                    i-=2;
                }
                isMoveS = true;
            }
            if (t[j] == '#') {
                if (t[j - 1] != '#')
                {
                    j-=2;//前一个是字母，要消除
                }
                else {//前一个也是#，消除这个和它之前的
                    t[j - 2] = '#';
                    j-=2;
                }
                isMoveT = true;
            }
            if ((s[i] != t[j]) && (s[i] != '#') && (t[j] != '#'))//只要不相等，就立马结束，但这里有一个特例，就是结尾是#，此时要  
            {
                return false;
            }
            if (isMoveS==false)//没有变化，说明后缀不是#，是字符，直接向前
                i--;
            if (isMoveT == false)
                j--;
        }
        return true;
    }
};
int main() {;
//string s = "ab#c", t = "ad#c";
    string s = "aa#";
    string t = "a";
    Solution o;
    bool res = o.backspaceCompare(s, t);
    cout << res << endl;
}
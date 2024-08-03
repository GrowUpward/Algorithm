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
                    i-=2;//ǰһ������ĸ��Ҫ����
                }
                else {//ǰһ��Ҳ��#�������������֮ǰ��
                    s[i - 2] = '#';
                    i-=2;
                }
                isMoveS = true;
            }
            if (t[j] == '#') {
                if (t[j - 1] != '#')
                {
                    j-=2;//ǰһ������ĸ��Ҫ����
                }
                else {//ǰһ��Ҳ��#�������������֮ǰ��
                    t[j - 2] = '#';
                    j-=2;
                }
                isMoveT = true;
            }
            if ((s[i] != t[j]) && (s[i] != '#') && (t[j] != '#'))//ֻҪ����ȣ��������������������һ�����������ǽ�β��#����ʱҪ  
            {
                return false;
            }
            if (isMoveS==false)//û�б仯��˵����׺����#�����ַ���ֱ����ǰ
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
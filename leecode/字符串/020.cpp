/**
 * 20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
 * 
 **/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool isValid(string s) {
    if (s.size()==1) return false;
    vector<char> res;
    for(int i=0;i<s.size();i++){
        // if(s[i]=='{' && s[i+1]=='}'){ i++;continue;}
        // else if(s[i]=='(' && s[i]==')'){ i++;continue;}
        // else if(s[i]=='[' && s[i+1]==']'){ i++;continue;}

        switch(s[i]){
            case '{':
            case '(':
            case '[':
                res.push_back(s[i]);
                break;
            case '}':
                if(res.size()==0) return false;
                if (res.back()=='{'){
                    res.pop_back();
                }else return false;
                break;
            case ')':
                if(res.size()==0) return false;
                if(res.back()=='(') res.pop_back();
                else return false;
                break;
            case ']':
                if(res.size()==0) return false;
                if(res.back()=='[') res.pop_back();
                else return false;
                break;
        }
    }
    if (res.size()==0) return true;
    else return false;
}
int main(){
    string s="]";
    cout << isValid(s) << endl;
}
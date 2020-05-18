/*
 * @Descripttion: 
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-03 18:01:26
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-13 17:39:46
 */
/*
    17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> res;

void sub(string digits,int index,string s){
    if(index==digits.length()){
        res.push_back(s);
        return;
    }
    string letters=dict[digits[index]-'0'];
    for(int i=0;i<letters.size();i++){
        sub(digits,index+1,s+letters.at(i));
    }
    return;
}

vector<string> letterCombinations(string digits)
{
    if(digits==""){
        return res;
    }
    sub(digits,0,"");
    return res;
}


int main(){
    string digites="";
    vector<string> result=letterCombinations(digites);
    for(auto a:result){
        cout << a << endl;
    }
}
/*
 * @Descripttion: 30. 串联所有单词的子串
        给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
        注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-10 18:34:07
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-13 16:15:24
 */
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
//776 ms    30.10%      80.2 MB     33.33%
vector<int> findSubstring(string s, vector<string>& words) {
    if(s.size()==0 || words.size()==0 ) return {};

    vector<int> res;

    map<string,int> hash;
    for(string word:words){
        hash[word]++;
    }
    int len=words[0].size();
    if(s.size()<len*words.size()) return res;

    for(int i=0;i<=s.size()-len*words.size();i++){
        string substr=s.substr(i,len*words.size());
        map<string,int> newhash;
        int j;
        for(j=0;j<substr.size();j+=len){
            string temp=substr.substr(j,len);
            newhash[temp]++;
            if(newhash[temp]>hash[temp]) break;
        }
        if(j==substr.size()) res.push_back(i);
    }
    return res;
}
//172 ms    62.92%      22.6 MB     66.67%
vector<int> findSubstring2(string s, vector<string>& words) {
    if(s.size()==0 || words.size()==0 ) return {};

    vector<int> res;

    map<string,int> hash;
    for(string word:words){
        hash[word]++;
    }
    int len=words[0].size();

    map<string,int> newhash;
    for(int i=0;i<len;i++){
        newhash.clear();

        if(i+len*words.size()>s.size()) break;
        int left=i;
        int j=left;
        for(;j<left+len*words.size() && left+len*words.size()<=s.size();j+=len){
            string temp=s.substr(j,len);
            if(hash.find(temp)==hash.end()){
                left=j+len;
                newhash.clear();
                continue;
            }
            newhash[temp]++;

        }
        if(newhash==hash) res.push_back(left);
        for(;j<s.size();j+=len){
            string temp=s.substr(left,len);
            newhash[temp]--;
            if(newhash[temp]==0) newhash.erase(temp);
            left+=len;
            newhash[s.substr(j,len)]++;
            if(newhash==hash) res.push_back(left);
        }
    }
    return res;
}

int main(){
    vector<string> words;
    words.push_back("cb");
    words.push_back("bc");
    // words.push_back("ab");
    // words.push_back("ding");
    // words.push_back("wing");
    vector<int> res=findSubstring2("cbaccbcbbc",words);
    for(int a:res){
        cout << a << endl;
    }
}

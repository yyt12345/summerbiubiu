/*
 * @Descripttion: 36. 有效的数独
        判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
        数字 1-9 在每一行只能出现一次。
        数字 1-9 在每一列只能出现一次。
        数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-15 11:36:59
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-15 13:46:50
 */
#include <vector>
#include <iostream>
#include <map>
using namespace std;
//  16 ms   71.70%      8 MB    100.00%
struct rect{
    int x;
    int y;
    rect(int curx,int cury){
        x=curx;
        y=cury;
    }
};
bool isValue(const rect& r1,const rect& r2){
    if(r1.x==r2.x || r1.y==r2.y) return false;
    if(r1.x/3==r2.x/3 && r1.y/3==r2.y/3) return false;
    return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    map<char,vector<rect> > hash;
    for(int j=0;j<board.size();j++){
        for(int i=0;i<board[0].size();i++){
            char c=board[j][i];
            if(c!='.'){
                rect temp(i,j);
                for(int i=0;i<hash[c].size();i++){
                    if(!isValue(temp,hash[c][i])) return false;
                }
                hash[c].push_back(temp);  
            }
        }
    }
    return true;
}
int main(){
    vector<vector<char> > board={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}                              
    };
    bool res=isValidSudoku(board);
    cout << res << endl;


}

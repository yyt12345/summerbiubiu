/*
18. 四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> >  res;
    if(nums.size()<4)   return res;
    sort(nums.begin(),nums.end());
    int _size=nums.size();
    for(int a=0;a<=_size-4;a++){
        if(a>0 && nums.at(a)==nums.at(a-1)) continue;
        for(int b=a+1;b<=_size-3;b++){
            if(b>a+1 && nums.at(b)==nums.at(b-1)) continue;
            int c=b+1,d=_size-1;
            while(c<d){
                if(nums.at(c)+nums.at(d)<target-nums.at(a)-nums.at(b)){
                    c++;
                    while(c<d && nums.at(c)==nums.at(c-1)) c++;
                }
                else if(nums.at(c)+nums.at(d)>target-nums.at(a)-nums.at(b)){
                    d--;
                    while(c<d && nums.at(d+1)==nums.at(d)) d--;
                }
                else {
                    res.push_back({nums.at(a),nums.at(b),nums.at(c),nums.at(d)});
                    c++;
                    while(c<d && nums.at(c)==nums.at(c-1)) c++;
                    d--;
                    while(c<d&&nums.at(d+1)==nums.at(d)) d--;
                }
            }
        }
    }
    return res;
}

// 264ms 7.2MB
vector<vector<int> > fourSum2(vector<int>& nums, int target) {
    vector<vector<int> >  res;
    if(nums.size()<4)   return res;
    sort(nums.begin(),nums.end());
    int _size=nums.size();
    for(int a=0;a<=_size-4;a++){
        if(a>0 && nums.at(a)==nums.at(a-1)) continue;
        for(int b=a+1;b<=_size-3;b++){
            if(b>a+1 && nums.at(b)==nums.at(b-1)) continue;
            int c=b+1,d=_size-1;
            while(c<d){
                int sum=nums.at(a)+nums.at(b)+nums.at(c)+nums.at(d);
                if(sum<target){
                    c++;
                    while(c<d && nums.at(c)==nums.at(c-1)) c++;
                }
                else if(sum>target){
                    d--;
                    while(c<d && nums.at(d+1)==nums.at(d)) d--;
                }
                else {
                    res.push_back({nums.at(a),nums.at(b),nums.at(c),nums.at(d)});
                    c++;
                    while(c<d && nums.at(c)==nums.at(c-1)) c++;
                    d--;
                    while(c<d&&nums.at(d+1)==nums.at(d)) d--;
                }
            }
        }
    }
    return res;
}

//增加条件判断
//48ms 7.2MB
vector<vector<int> > fourSum3(vector<int>& nums, int target) {
    vector<vector<int> >  res;
    if(nums.size()<4)   return res;
    sort(nums.begin(),nums.end());
    int _size=nums.size();
    for(int a=0;a<=_size-4;a++){
        if(a>0 && nums.at(a)==nums.at(a-1)) continue;

        if(nums[a]+nums[a+1]+nums[a+2]+nums[a+3]>target) continue;
        if(nums[_size-4]+nums[_size-1]+nums[_size-2]+nums[_size-3]<target) continue;

        for(int b=a+1;b<=_size-3;b++){
            if(b>a+1 && nums.at(b)==nums.at(b-1)) continue;
            
            int c=b+1,d=_size-1;
            while(c<d){
                int sum=nums.at(a)+nums.at(b)+nums.at(c)+nums.at(d);
                if(sum<target) 
                    while(c<d && nums[c]==nums[++c]);
                else if(sum>target)
                    while(c<d && nums[d]==nums[--d]);
                else{
                    res.push_back({nums[a],nums[b],nums[c],nums[d]});
                    while(c<d && nums[c]==nums[++c]);
                    while(c<d && nums[d]==nums[--d]);
                }
            }
        }
    }
    return res;
}


int main(){
    vector<int> nums={0,0,0,0};
    vector<vector<int> > res=fourSum3(nums,1);
    for (auto col:res){
        for(auto n:col){
            cout << n << " ";
        }
        cout << endl;
    }

}
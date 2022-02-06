/****************************************************************************************
*  @author: kzvd4729                                         created: 03/06/2021 02:12                         
*  solution_verdict: Wrong Answer                            language: cpp                                     
*  run_time: N/A                                             memory_used: N/A                                  
*  problem: https://leetcode.com/problems/rectangle-area-ii
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int vs[1000+2][1000+2];
class Solution
{
public:
  int rectangleArea(vector<vector<int>>& rectangles)
  {
    vector<vector<int> >v=rectangles;
        vector<int>a;
    for(auto x:v)
    {
      a.push_back(x[0]);a.push_back(x[2]);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    vector<int>row,col;
    for(int i=0;i<(int)a.size()-1;i++)
    {
      row.push_back(a[i+1]-a[i]);
    }
    vector<int>b;
    for(auto x:v)
    {
      b.push_back(x[1]);b.push_back(x[3]);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=0;i<(int)b.size()-1;i++)
    {
      col.push_back(b[i+1]-b[i]);
    }
    for(auto x:v)
    {
      int i1=lower_bound(a.begin(),a.end(),x[0])-a.begin();
      int i2=lower_bound(a.begin(),a.end(),x[2])-a.begin();
      int j1=lower_bound(b.begin(),b.end(),x[1])-b.begin();
      int j2=lower_bound(b.begin(),b.end(),x[3])-b.begin();
      for(int i=i1;i<i2;i++)
      {
        for(int j=j1;j<j2;j++)vs[i][j]=1;
      }
    }
    long ans=0;
    for(int i=0;i<(int)row.size();i++)
    {
      for(int j=0;j<(int)col.size();j++)
      {
        ans=(ans+1LL*row[i]*col[j]*vs[i][j])%mod;
      }
    }
    return (int)ans;
  }
};
/****************************************************************************************
*  @author: kzvd4729                                         created: 06/06/2021 20:30                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 40 ms                                           memory_used: 25.2 MB                              
*  problem: https://leetcode.com/problems/longest-consecutive-sequence
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
const int sz=3e5;//more size better
struct hashtable
{
  int key[sz+2];
  bool val[sz+2];//can be any data type
  static inline int h(int x){return(((x^179)*7LL)%sz+sz)%sz;}
  void init()
  {
    memset(key,-1,sizeof key);//-1 is invalid
    memset(val,0,sizeof val);
  }
  void add(int x,int y)//assign
  {
    int k=h(x);
    while(key[k]!=-1&&key[k]!=x)k=(k+1)%sz;//first non-taken index
    key[k]=x,val[k]=y;
  }
  int get(int x)
  {
    for(int k=h(x);key[k]!=-1;k=(k+1)%sz)
      if(key[k]==x)return val[k];
    return 0;
  }
}mp,vs;
class Solution {
public:
    int longestConsecutive(vector<int>& a) 
    { 
      mp.init();vs.init();
      if((int)a.size()==0)return 0;
      for(auto x:a)mp.add(x,1);
      int mx=0;
      for(auto x:a)
      {
        //cout<<"*"<<x<<endl;
        if(vs.get(x))continue;
        vs.add(x,1);int cnt=1;
        for(int i=x+1; ;i++)
        {
          if(mp.get(i))cnt++,vs.add(i,1);
          else break;
        }
        for(int i=x-1; ;i--)
        {
          if(mp.get(i))cnt++,vs.add(i,1);
          else break;
        }
        mx=max(mx,cnt);
      }
      return mx;
    }
};
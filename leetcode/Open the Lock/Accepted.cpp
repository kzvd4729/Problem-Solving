/****************************************************************************************
*  @author: kzvd4729                                         created: 06/04/2021 16:18                         
*  solution_verdict: Accepted                                language: cpp                                     
*  run_time: 1368 ms                                         memory_used: 346.6 MB                             
*  problem: https://leetcode.com/problems/open-the-lock
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
const int N=1e6,inf=1e9,mod=1000000007;
int stringToNum(string x)
{
  if((int)x.size()==0)assert(0);
  int ml=1,b=0,ret=0;
  for(int i=b;i<(int)x.size();i++)
    ret=ret*10+x[i]-'0';
  return ret*ml;
}
vector<string>nxt(string s)
{
  vector<string>ret;
  for(int i=0;i<4;i++)
  {
    string tmp=s;
    if(tmp[i]=='9')tmp[i]='0';
    else tmp[i]++;
    ret.push_back(tmp);
    tmp=s;
    if(tmp[i]=='0')tmp[i]='9';
    else tmp[i]--;
    ret.push_back(tmp);
  }
  return ret;
}
class Solution {
public:
  int openLock(vector<string>& a, string tar) 
  {
    vector<int>bad(10000,0),ds(10000,inf);
    for(auto x:a)bad[stringToNum(x)]=1;
    if(bad[0])return -1;
    queue<string>q;q.push("0000");ds[0]=0;
    while((int)q.size())
    {
      string u=q.front();q.pop();
      int d=ds[stringToNum(u)];
      vector<string>nx=nxt(u);
      for(auto x:nx)
      {
        if(d+1<ds[stringToNum(x)] && bad[stringToNum(x)]==0)
        {
          ds[stringToNum(x)]=d+1;
          q.push(x);
        }
      }
    }
    if(ds[stringToNum(tar)]==inf)return -1;
    return ds[stringToNum(tar)];
  }
};
/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/03/2020 17:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 342 ms                                          memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/292/problem/C
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
const int N=1e6;
int n,a[N+2];
vector<string>ans;
void make(vector<int>v,int a,int b,int c)
{
  string s;
  for(int i=0;i<(int)v.size();i++)
  {
    s.push_back((char)(v[i]+'0'));
    if(i==a||i==b||i==c)s.push_back('.');
  }
  ans.push_back(s);
}
void ck(vector<int>v)
{
  int sz=v.size();
  for(int i=0;i<sz-1;i++)
  {
    for(int j=i+1;j<sz-1;j++)
    {
      for(int k=j+1;k<sz-1;k++)
      {
        int a=0;
        for(int l=0;l<=i;l++)
          a=a*10+v[l];
        if(a>255||(v[0]==0&&i))continue;
         a=0;
        for(int l=i+1;l<=j;l++)
          a=a*10+v[l];
        if(a>255||(v[i+1]==0&&j-i>1))continue;
         a=0;
        for(int l=j+1;l<=k;l++)
          a=a*10+v[l];
        if(a>255||(v[j+1]==0&&k-j>1))continue;
         a=0;
        for(int l=k+1;l<sz;l++)
          a=a*10+v[l];
        if(a>255||(v[k+1]==0&&sz-k>2))continue;
         make(v,i,j,k);
       }
    }
  }
}
void dfs(int ln,int tk,int msk,vector<int>v)
{
  if((ln+1)/2==tk)
  {
    if(msk!=(1<<n)-1)return ;
     vector<int>u=v;
     if(ln%2==0)
    {
      for(int i=(int)v.size()-1;i>=0;i--)u.push_back(v[i]);
    }
    else
    {
      for(int i=(int)v.size()-2;i>=0;i--)u.push_back(v[i]);
    }
    ck(u);
    return ;
  }
  for(int i=1;i<=n;i++)
  {
    v.push_back(a[i]);
    dfs(ln,tk+1,msk|(1<<(i-1)),v);
    v.pop_back();
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int ln=4;ln<=12;ln++)
  {
    vector<int>v;
    dfs(ln,0,0,v);
  }
  cout<<(int)ans.size()<<'\n';
  for(auto x:ans)cout<<x<<'\n';
   return 0;
}
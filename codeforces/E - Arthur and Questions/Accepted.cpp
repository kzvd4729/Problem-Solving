/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/14/2020 19:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/518/problem/E
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
const int N=1e5,inf=1e9+N+N;
int stringToNum(string x)
{
  if((int)x.size()==0)assert(0);
  int ml=1,b=0,ret=0;
  if(x[0]=='-')ml=-1,b=1;
  for(int i=b;i<(int)x.size();i++)
    ret=ret*10+x[i]-'0';
  return ret*ml;
}
int a[N+2];
void no()
{
  cout<<"Incorrect sequence"<<endl,exit(0);
}
void solve(vector<int>&v)
{
  int l=-inf-1;vector<int>bf;v.push_back(inf+1);
  //for(auto x:v)cout<<x<<" ";cout<<endl;
  for(int i=0;i<(int)v.size();i++)
  {
    if(v[i]>inf+1)bf.push_back(i);
    else
    {
      if((int)bf.size()>v[i]-l-1)no();
       if(l<=0&&v[i]<=0)
      {
        int now=v[i];
        for(int j=(int)bf.size()-1;j>=0;j--)v[bf[j]]=--now;
      }
      else if(l>=0&&v[i]>=0)
      {
        int now=l;
        for(int j=0;j<(int)bf.size();j++)v[bf[j]]=++now; 
      }
      else
      {
        int lt=0,rt=0;
        while(rt-lt+1<(int)bf.size())
        {
          if(lt-1>l)lt--;
          if(rt+1<v[i])rt++;
        }
        for(int j=0;j<(int)bf.size();j++)v[bf[j]]=lt++; 
      }
      bf.clear();l=v[i];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    if(s=="?")a[i]=inf+2;
    else a[i]=stringToNum(s);
  }
  for(int i=1;i<=k;i++)
  {
    vector<int>v;
    for(int j=i;j<=n;j+=k)v.push_back(a[j]);
    solve(v);int id=0;
    for(int j=i;j<=n;j+=k)a[j]=v[id++];
  }
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
  return 0;
}
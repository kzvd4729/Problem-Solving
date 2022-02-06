/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/03/2020 12:10                        
*  solution_verdict: Wrong answer on test 15                 language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 244500 KB                            
*  problem: https://codeforces.com/contest/979/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#define long long long
using namespace std;
const int N=1e5;
vector<int>dd[N+2];
void divisors()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)dd[j].push_back(i);
  }
}
int sz,tr[30000000+2][2];
void add(int x,int now)
{
  for(int i=16;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(!tr[now][z])tr[now][z]=++sz;
    now=tr[now][z];
  }
}
int get(int x,int now,int s)
{
  int ad=0,f=0;int rnow=-1,rad,j;
  for(int i=16;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(tr[now][!z]&&x+ad+((!z)<<i)<=s)
    {
      if(tr[now][z]&&x+ad+(z<<i)<=s)
      {
        rnow=tr[now][z],rad=ad|(z<<i);
        j=i-1;
      }
      now=tr[now][!z],ad|=((!z)<<i);
    }
    else if(tr[now][z]&&x+ad+(z<<i)<=s)now=tr[now][z],ad|=(z<<i);
    else {f=1;break;}
  }
  if(!f)return ad;
  now=rnow,ad=rad;
  for(int i=j;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(tr[now][!z]&&x+ad+((!z)<<i)<=s)now=tr[now][!z],ad|=((!z)<<i);
    else if(tr[now][z]&&x+ad+(z<<i)<=s)now=tr[now][z],ad|=(z<<i);
    else return -1;
  }
  return ad;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  divisors();sz=N;
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int ty;cin>>ty;
    if(ty==1)
    {
      int x;cin>>x;
      for(auto z:dd[x])add(x,z);
    }
    else
    {
      int x,k,s;cin>>x>>k>>s;
      if(x%k)cout<<-1<<"\n";
      else cout<<get(x,k,s)<<"\n";
    }
  }
  return 0;
}
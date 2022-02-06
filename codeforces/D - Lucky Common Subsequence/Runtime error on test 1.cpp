/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/10/2018 15:59                        
*  solution_verdict: Runtime error on test 1                 language: GNU C++14                               
*  run_time: 248 ms                                          memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/347/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
string a,b,v;
int kmp[N+2];
void _kmp(string s)
{
  kmp[0]=0;
  for(int i=1;s[i];i++)
  {
    int now=kmp[i-1];
    while(true)
    {
      if(s[now]==s[i])
      {
        kmp[i]=now+1;
        break;
      }
      if(!now)break;
      now=kmp[now-1];
    }
  }
}
int dfs(int i,int j,int k)
{
  int here=0;
  here=max(here,dfs(i+1,j,k));
  here=max(here,dfs(i,j+1,k));
  if(a[i]==b[j])
  {
    if(a[i]!=v[k])
      here=max(here,1+dfs(i+1,j+1,kmp[k]));
    else if(k<v.size()-1)
      here=max(here,1+dfs(i+1,j+1,k+1));
  }
  return here;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b>>v;_kmp(v);
  cout<<dfs(0,0,0)<<endl;
  return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/08/2019 15:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 6100 KB                              
*  problem: https://codeforces.com/contest/1137/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int kmp[N+2];
void make_kmp(string s)
{
  kmp[0]=0;int n=s.size();
  for(int i=1;i<n;i++)
  {
    int now=kmp[i-1];
    while(true)
    {
      if(s[now]==s[i])
      {
        kmp[i]=now+1;break;
      }
      if(!now)break;
      now=kmp[now-1];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;int on=0,zr=0;
  for(auto x:a)
  {
    if(x=='1')on++;
    else zr++;
  }
  make_kmp(b);int n=b.size();
  int now=0;
  for(int i=0;i<a.size();i++)
  {
    if(now==n)now=kmp[n-1];
    if(b[now]=='1')
    {
      if(on)
      {
        cout<<'1';
        on--;
      }
      else break;
    }
    else
    {
      if(zr)
      {
        cout<<'0';
        zr--;
      }
      else break;
    }
    now++;
  }
  while(on--)cout<<'1';
  while(zr--)cout<<'0';
  cout<<endl;
  return 0;
}
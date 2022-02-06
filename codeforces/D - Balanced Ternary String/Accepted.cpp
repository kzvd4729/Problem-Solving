/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/09/2019 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/1102/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;int zr=0,on=0,tw=0;
  for(auto x:s)
  {
    if(x=='0')zr++;
    if(x=='1')on++;
    if(x=='2')tw++;
  }
  int rq=n/3;
   if(zr>rq)
  {
    int cnt=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]!='0')continue;
      if(cnt<rq)cnt++;
      else
      {
        if(on<rq)
        {
          s[i]='1';on++;
        }
        else
        {
          s[i]='2';tw++;
        }
        zr--;
      }
    }
  }
    if(on>rq&&zr<rq)
  {
    for(int i=0;i<n;i++)
    {
      if(s[i]!='1')continue;
      if(on>rq&&zr<rq)
      {
        s[i]='0';
        on--;zr++;
      }
    }
  }
   if(on>rq)
  {
    int cnt=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]!='1')continue;
      if(cnt<rq)cnt++;
      else
      {
        if(zr<rq)
        {
          s[i]='0';zr++;
        }
        else
        {
          s[i]='2';tw++;
        }
        on--;
      }
    }
  }
    if(tw>rq)
  {
    for(int i=0;i<n;i++)
    {
      if(s[i]!='2')continue;
      if(tw>rq)
      {
        if(zr<rq)
        {
          s[i]='0';zr++;
        }
        else
        {
          s[i]='1';on++;
        }
        tw--;
      }
    }
  }
  cout<<s<<endl;
  return 0;
}
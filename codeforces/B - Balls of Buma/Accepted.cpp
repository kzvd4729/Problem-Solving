/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2019 13:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 5000 KB                              
*  problem: https://codeforces.com/contest/1267/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int cnt[N+2];
void no(){cout<<0<<endl,exit(0);}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s,a;cin>>s;
   int now=0;
  for(auto x:s)
  {
    if(a.size()==0)a.push_back(x),now=1;
    else
    {
      if(a.back()!=x)
      {
        cnt[a.size()-1]=now;
        a.push_back(x);now=1;
      }
      else now++;
    }
  }
  cnt[a.size()-1]=now;
   int n=a.size();if(n%2==0)no();
  for(int i=0;i<n;i++)
  {
    if(cnt[i]+cnt[n-1-i]<3)no();
    if(a[i]!=a[n-1-i])no();
  }
  cout<<cnt[n/2]+1<<endl;
   return 0;
}
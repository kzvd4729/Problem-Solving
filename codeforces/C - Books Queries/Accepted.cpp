/****************************************************************************************
*  @author: * kzvd4729                                       created: Oct/12/2018 21:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/1066/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int qm[N+2],mq[N+2];
map<int,int>mp;char ty[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    qm[i]=qm[i-1];mq[i]=mq[i-1];
     char c;int id;cin>>c>>id;
    ty[i]=c;
    if(c=='L')qm[i]++,mp[id]=i;
    else if(c=='R')mq[i]++,mp[id]=i;
    else
    {
      id=mp[id];
       int pl=qm[i]-qm[id],pr=mq[i]-mq[id];
       if(ty[id]=='L')
      {
        cout<<min(pl,mq[i]+qm[id-1])<<"\n";
      }
      else
      {
        cout<<min(pr,qm[i]+mq[id-1])<<"\n";
      }
    }
  }
  return 0;
}
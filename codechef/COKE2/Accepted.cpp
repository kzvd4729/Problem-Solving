/****************************************************************************************
*  @author: kzvd4729                                         created: 31-08-2019 21:07:13                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.25 sec                                        memory_used: 53M                                  
*  problem: https://www.codechef.com/LTIME75A/problems/COKE2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
const int inf=1e9;
int ans[N+2];
pair<int,int>pp[N+2],qq[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,q,k,l,r;cin>>n>>q>>k>>l>>r;
    int a=0,b=0;
    for(int i=1;i<=n;i++)
    {
      int c,p;cin>>c>>p;
      if(c>=k)pp[++a]={c,p};
      else qq[++b]={c,p};
    }
    if(a)sort(pp+1,pp+a+1);
    if(b)sort(qq+1,qq+b+1,greater<pair<int,int> >());
    for(int i=1;i<=q;i++)ans[i]=inf;
    int pt=1;deque<pair<int,int> >dq;
    for(int i=1;i<=q;i++)
    {
      while(pt<=a)
      {
        if(max(pp[pt].first-i,k)<=r)
        {
          while(dq.size())
          {
            if(dq.back().second<pp[pt].second)break;
            else dq.pop_back();
          }
          dq.push_back(pp[pt]);
          pt++;
        }
        else break;
      }
      while(dq.size())
      {
        if(max(dq.front().first-i,k)<l)dq.pop_front();
        else break;
      }
      if(dq.size())
      {
        ans[i]=min(ans[i],dq.front().second);
      }
    }
    while(dq.size())dq.pop_back();
    pt=1;
    for(int i=1;i<=q;i++)
    {
      while(pt<=b)
      {
        if(min(qq[pt].first+i,k)>=l)
        {
          while(dq.size())
          {
            if(dq.back().second<qq[pt].second)break;
            else dq.pop_back();
          }
          dq.push_back(qq[pt]);
          pt++;
        }
        else break;
      }
      while(dq.size())
      {
        if(min(dq.front().first+i,k)>r)dq.pop_front();
        else break;
      }
      if(dq.size())ans[i]=min(ans[i],dq.front().second);
    }
    for(int i=1;i<=q;i++)
    {
      if(ans[i]==inf)ans[i]=-1;
      cout<<ans[i];
      if(i==q)cout<<"\n";
      else cout<<" ";
    }
  }
  return 0;
}
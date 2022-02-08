/****************************************************************************************
*  @author: kzvd4729                                         created: 16-09-2018 20:18:51                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/SEPT18A/problems/ANDSQR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int D=31;
int arr[N+2],nxt[N+2][D+2];
vector<pair<int,int> >vc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];vc[i].clear();
      memset(nxt[i],0,sizeof(nxt[i]));
    }
    for(int i=n;i>=1;i--)
    {
      for(int j=0;j<D;j++)
      {
        if((arr[i]&(1<<j)))nxt[i][j]=nxt[i+1][j];
        else nxt[i][j]=i;
      }
    }
    for(int i=1;i<=n;i++)
    {
      int tmp=arr[i],id=i;vector<int>v;
      for(int j=0;j<D;j++)
      {
        if((tmp&(1<<j))&&nxt[i][j])
        {
          v.push_back(nxt[i][j]);
        }
      }
      sort(v.begin(),v.end());
      reverse(v.begin(),v.end());
      while(true)
      {
        if(v.size()==0)
        {
          if(sqrt(tmp)*sqrt(tmp)==tmp)
          {
            vc[i].push_back({id,n});
          }
          break;
        }
        if(sqrt(tmp)*sqrt(tmp)==tmp)
        {
          vc[i].push_back({id,v.back()-1});
        }
        id=v.back();tmp&=arr[id];
        while(v.size())
        {
          if(v.back()==id)v.pop_back();
          else break;
        }
      }
    }
//    for(int i=1;i<=n;i++)
//    {
//      cout<<endl<<endl;
//      cout<<i<<endl;
//      for(auto x:vc[i])
//        cout<<x.first<<" "<<x.second<<endl;
//    }
    while(q--)
    {
      int l,r;cin>>l>>r;
      long ans=0;
      for(int i=l;i<=r;i++)
      {
        for(auto x:vc[i])
        {
          int add=min(r,x.second)-max(l,x.first)+1;
          ans+=max(0LL,add*1LL);
        }
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}
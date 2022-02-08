/****************************************************************************************
*  @author: kzvd4729                                         created: 24-11-2018 20:40:39                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/LTIME66A/problems/BPS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=20;
int aa[N+2],bb[N+2],cc[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    vector<int>v;
    int n,m,cnt=0;cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>aa[i];
    for(int i=1;i<=n;i++)bb[i]=aa[i];
    for(int i=1;i<=m;i++)
    {
      cin>>pp[i].first>>pp[i].second;
    }
    for(int i=1;i<=m;i++)
    {
      int pt=pp[i].first;
      for(int j=pp[i].second;j>=pp[i].first;j--)
        bb[pt++]=aa[j];
    }
    for(int i=1;i<=m;i++)v.push_back(i);
    do
    {
      for(int i=1;i<=n;i++)
        cc[i]=aa[i];
      for(auto x:v)
      {
        int pt=pp[x].first;
        for(int j=pp[x].second;j>=pp[x].first;j--)
          bb[pt++]=aa[j];
      }
      int f=0;
      for(int i=1;i<=n;i++)
        if(cc[i]!=aa[i])f=1;
      if(!f)cnt++;
    }while(next_permutation(v.begin(),v.end()));
        int q=1;
    for(int i=2;i<=m;i++)q*=i;
    int gcd=__gcd(cnt,q);
    cout<<cnt/gcd<<"/"<<q/gcd<<endl;
  }
  return 0;
}
/****************************************************************************************
*  @author: kzvd4729                                         created: 24-11-2018 20:54:53                      
*  solution_verdict: Time Limit Exceeded                     language: C++14                                   
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
      vector<int>tmp;
      for(int j=pp[i].second;j>=pp[i].first;j--)
        tmp.push_back(bb[j]);
      int pt=0;
      for(int j=pp[i].first;j<=pp[i].second;j++)
        bb[j]=tmp[pt++];
    }
    // for(int i=1;i<=n;i++)
    //   cout<<bb[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=m;i++)v.push_back(i);
    do
    {
      for(int i=1;i<=n;i++)
        cc[i]=aa[i];
      for(auto i:v)
      {
        vector<int>tmp;
        for(int j=pp[i].second;j>=pp[i].first;j--)
          tmp.push_back(cc[j]);
        int pt=0;
        for(int j=pp[i].first;j<=pp[i].second;j++)
          cc[j]=tmp[pt++];
      }
      int f=0;
      for(int i=1;i<=n;i++)
        if(cc[i]!=bb[i])f=1;
      if(!f)cnt++;
    }while(next_permutation(v.begin(),v.end()));
        int q=1;
    for(int i=2;i<=m;i++)q*=i;
    int gcd=__gcd(cnt,q);
    cout<<cnt/gcd<<"/"<<q/gcd<<endl;
  }
  return 0;
}
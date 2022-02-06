/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/11/2019 23:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 233 ms                                          memory_used: 12100 KB                             
*  problem: https://codeforces.com/gym/102215/problem/M
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int qm[N+2];
pair<int,int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
   int n;cin>>n;vector<pair<int,int> >v;
   for(int i=1;i<=n;i++)
   {
    cin>>pp[i].first>>pp[i].second;
    v.push_back({pp[i].first,i});
   }
   sort(v.begin(),v.end());reverse(v.begin(),v.end());
   sort(pp+1,pp+n+1);reverse(pp+1,pp+n+1);
    int sm=0,up=0;
   for(int i=1;i<=n;i++)
   {
    qm[i]=qm[i-1]+pp[i].first;
    up+=pp[i].first*pp[i].second;
    sm+=pp[i].second;
   }
   double mx=(up*1.0)/(sm*1.0);int til=0;
   for(int i=1;i<=n;i++)
   {
    double now=((up+qm[i])*1.0)/((sm+i)*1.0);
    if(now>mx)mx=now,til=i;
   }
   up+=qm[til],sm+=til;
   int gc=__gcd(up,sm);
   cout<<up/gc<<"/"<<sm/gc<<endl;
   cout<<til<<endl;
   for(int i=0;i<til;i++)cout<<v[i].second<<" ";
    cout<<endl;
  }
  return 0;
}